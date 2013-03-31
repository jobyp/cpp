#include <vector>
#include <string>
#include <cctype>
#include <iostream>

#include "lib_str.h"

using std::vector;
using std::string;
using std::getline;
using std::cout;
using std::cin;
using std::endl;

int main()
{
        string line;

        // while(getline(cin, line)) {
                
        //         const vector<string>& words = split(line);
                
        //         for(vector<string>::const_iterator it = words.begin();
        //             it != words.end();
        //             ++it)
        //                 cout << *it << endl;
        // }

        cout << "***" << strip(string("This is fun.\nYou shouldn't see this.")) << "***" << endl;
        
        return 0;
}
