#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "lib_str.h"

using std::vector;
using std::string;
using std::max_element;
using std::max;
using std::min;
using std::for_each;
using std::getline;
using std::cin;
using std::cout;
using std::endl;

static bool str_size_cmp(const string& s1, const string& s2)
{
        return (s1.size() < s2.size());
}

static string add_padding(const string& s, string::size_type len)
{
        return (s + string(len - s.size(), ' '));
} 

static string::size_type width(const vector<string>& p)
{
        if (p.size() == 0)
                return 0;
        
        const string& max_s = *max_element(p.begin(), p.end(), str_size_cmp);
        return max_s.size();
}

vector<string> frame(const vector<string>& p)
{
        string::size_type maxlen = width(p);
        vector<string> ret;
        string border(maxlen + 4, '*');
        
        ret.push_back(border);
        for (vector<string>::const_iterator it = p.begin(); it != p.end(); it++)
                ret.push_back("* " + add_padding(*it, maxlen) + " *");
        ret.push_back(border);

        return ret;
}

vector<string> vcat(const vector<string>& top, const vector<string>& bottom)
{
        vector<string> ret(top);
        ret.insert(ret.end(), bottom.begin(), bottom.end());
        return ret;
}

vector<string> hcat(const vector<string>& l, const vector<string>& r)
{
        if (l.size() == 0)
                return r;
        
        if (r.size() == 0)
                return l;
        
        vector<string>::size_type max_rows = max(l.size(), r.size());
        vector<string>::size_type min_rows = min(l.size(), r.size());
        
        string::size_type left_col = (l.begin())->size();
        string::size_type right_col = (r.begin())->size();
        
        if (left_col == 0)
                return r;
        if (right_col == 0)
                return l;
        
        string l_spaces(left_col, ' ');
        string r_spaces(right_col, ' ');
        
        vector<string> ret;
        vector<string>::size_type i;
        for (i = 0; i < min_rows; i++)
                ret.push_back(l[i] + " " + r[i]);

        if (i == l.size())
                for(; i < max_rows; i++)
                        ret.push_back(l_spaces + " " + r[i]);
        else
                for(; i < max_rows; i++)
                        ret.push_back(l[i] + " " + r_spaces);
        
        return ret;
}

vector<string> hcat2(const vector<string>& left, const vector<string>& right)
{
        vector<string> ret;
        string::size_type width1 = width(left) + 1;
        vector<string>::size_type i = 0, j = 0;
        
        while(i != left.size() || j != right.size()) {
                string s;

                if (i != left.size())
                        s = left[i++];
                s += string(width1 - s.size(), ' ');

                if (j != right.size())
                        s += right[j++];

                ret.push_back(s);
        }
        
        return ret;
}


static void print_str(const string& s)
{
        cout << s << endl;
}

int main()
{
        string line;
        vector<vector<string> > pics;
        
        while(getline(cin, line))  {
                const vector<string>& words = split(line);
                pics.push_back(frame(words));
        }

        vector<string> pic;
        for(vector<vector<string> >::size_type i = 0; i != pics.size(); i++)
                pic = hcat2(pic, pics[i]);

        for_each(pic.begin(), pic.end(), print_str);
        return 0;
}
