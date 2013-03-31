#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <stdexcept>

#include "student_info.h"
#include "student_grade.h"
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
