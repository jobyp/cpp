#ifndef __STUDENT_INFO
#define __STUDENT_INFO

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
