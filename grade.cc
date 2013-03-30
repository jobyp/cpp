#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <stdexcept>

#include "student_info.h"
#include "median.h"

using std::vector;
using std::sort;
using std::cin;
using std::cout;
using std::string;
using std::domain_error;
using std::streamsize;
using std::endl;
using std::for_each;
using std::setprecision;

static double grade(double midterm, double final, double homework)
{
        return (0.2 * midterm + 0.4 * final + 0.4 * homework);
}

static double grade(double midterm, double final, const vector<double>& homework)
{
        if (homework.size() == 0)
                throw domain_error("student has done no homework");

        return grade(midterm, final, median(homework));
}

static double grade(const Student_info& s)
{
        return grade(s.midterm, s.final, s.homework);
}

class Print_grade {
        string::size_type name_width;
public:
        Print_grade(string::size_type nw) { name_width = nw; }
        void operator() (const Student_info&);
};

void Print_grade::operator() (const Student_info& s)
{
        cout << s.name 
             << string(name_width + 1 - s.name.size(), ' ');
        double final_grade;

        try {
                final_grade = grade(s);
        } catch (domain_error e) {
                cout << " -- " << e.what() << endl;
                return;
        }
        
        streamsize prec = cout.precision();
        cout << setprecision(3) 
             << final_grade
             << setprecision(prec)
             << endl;
        return;
}


int main()
{
        using namespace std;
        
        vector<Student_info> students;
        Student_info record;
        string::size_type maxlen = 0;

        while(read(cin, record)) {
                maxlen = max(maxlen, record.name.size());
                students.push_back(record);
        }
        
        sort(students.begin(), students.end(), compare);

        for_each(students.begin(), students.end(), Print_grade(maxlen));
        
        return 0;
}
