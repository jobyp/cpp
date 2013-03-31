#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <list>
#include <numeric>
#include <algorithm>
#include <stdexcept>

#include "student_info.h"
#include "student_grade.h"
#include "median.h"

using std::list;
using std::sort;
using std::max;
using std::cin;
using std::cout;
using std::string;
using std::domain_error;
using std::streamsize;
using std::endl;
using std::for_each;
using std::setprecision;

list<Student_info> extract_fails(list<Student_info>& students)
{
        list<Student_info> fail;
        list<Student_info>::iterator iter = students.begin();

        while(iter != students.end())
                if (fgrade(*iter)) {
                        fail.push_back(*iter);
                        iter = students.erase(iter);
                } 
                else 
                        iter++;
        return fail;
}

static void print_student_name(const Student_info& s)
{
        cout << s.name << endl;
}

int main()
{
        list<Student_info> students;
        Student_info record;
        string::size_type maxlen = 0;

        while(read(cin, record)) {
                maxlen = max(maxlen, record.name.size());
                students.push_back(record);
        }
        
        students.sort(compare);
        
        for_each(students.begin(), students.end(), Print_grade(maxlen));
        
        const list<Student_info>& fail = extract_fails(students);
        for_each(fail.begin(), fail.end(), print_student_name);

        return 0;
}
