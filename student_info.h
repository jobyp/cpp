#ifndef __STUDENT_INFO_H
#define __STUDENT_INFO_H

#include <string>
#include <vector>
#include <iostream>

struct Student_info {
        std::string name;
        double midterm;
        double final;
        std::vector<double> homework;
};

bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);

#endif
