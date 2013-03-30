#include <istream>
#include <vector>

#include "student_info.h"

using std::istream;
using std::vector;

bool compare(const Student_info& s1, const Student_info& s2)
{
        return (s1.name < s2.name);
}


istream& read(istream& in, Student_info& s)
{
        in >> s.name >> s.midterm >> s.final;
        return read_hw(in, s.homework);
}

istream& read_hw(istream& in, vector<double>& homework)
{
        if (!in) return in;
        
        homework.clear();

        double x;
        while(in >> x)  homework.push_back(x);
        
        in.clear();        

        return in;
}
