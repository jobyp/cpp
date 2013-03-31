#ifndef __STUDENT_GRADE_H
#define __STUDENT_GRADE_H

#include <vector>

#include "student_info.h"

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const Student_info&);
bool fgrade(const Student_info&);

class Print_grade {
        std::string::size_type name_width;
public:
        Print_grade(std::string::size_type nw) { name_width = nw; }
        void operator() (const Student_info&);
};

#endif
