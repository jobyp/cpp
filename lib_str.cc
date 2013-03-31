#include <vector>
#include <string>

#include "lib_str.h"

using std::vector;
using std::string;

vector<string> split(const string& s)
{
        vector<string> ret;
        typedef string::size_type string_size;

        string_size i = 0;

        while(i != s.size()) {
                
                // ignore leading whitespaces
                while((i != s.size()) && isspace(s[i]))  
                        ++i;
                
                // find the next word
                string_size j = i;
                
                while((j != s.size()) && !isspace(s[j]))
                        ++j;

                if (i != j) {
                        ret.push_back(s.substr(i, j - i));
                        i = j;
                }
        }
        
        return ret;
}

string strip(const string& s)
{
        string::size_type i = 0;
        
        while((i != s.size()) && (s[i] != '\n'))
                i++;

        string::size_type j = i;
        while((j != 0) && !isspace(s[j]))
                --j;
        
        if (j != i) // for the patholigical case where s is "" or "\nxxxxx"
                i = j + 1;
        
        if (i != 0)
                return s.substr(0, i);
        else
                return string("");
}
