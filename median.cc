#include <algorithm>
#include <stdexcept>
#include <vector>

#include "median.h"

using std::sort;
using std::domain_error;
using std::vector;

double median(vector<double> vec)
{
        vector<double>::size_type size = vec.size();

        if (size == 0)
                throw domain_error("median of an empty vector<double>");

        sort(vec.begin(), vec.end());

        vector<double>::size_type mid = vec.size() / 2;

        return ((size % 2) == 0) ? ((vec[mid] + vec[mid - 1]) / 2) : vec[mid];
}
