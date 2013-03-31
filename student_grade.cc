#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

#include "student_info.h"
#include "student_grade.h"
#include "median.h"

using std::vector;
using std::domain_error;
using std::cout;
using std::endl;
using std::setprecision;
using std::streamsize;
using std::string;

double grade(double midterm, double final, double homework)
{
        return (0.2 * midterm + 0.4 * final + 0.4 * homework);
}

double grade(double midterm, double final, const vector<double>& homework)
{
        if (homework.size() == 0)
                throw domain_error("student has done no homework");

        return grade(midterm, final, median(homework));
}

double grade(const Student_info& s)
{
        return grade(s.midterm, s.final, s.homework);
}

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

bool fgrade(const Student_info& s)
{
        return (grade(s) < 60);
}


