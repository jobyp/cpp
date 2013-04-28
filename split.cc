#include <string>
#include <cctype>
#include <algorithm>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::isspace;
using std::find_if;
using std::cin;
using std::cout;
using std::getline;
using std::endl;

static bool space(char c)
{
	return isspace(c);
}

static bool not_space(char c)
{
	return !isspace(c);
}

vector<string> split(const string& str)
{
	vector<string> ret;
	typedef string::const_iterator iter;

	iter i = str.begin();
	
	while(i != str.end()) {
		
		i = find_if(i, str.end(), not_space);
		iter j = find_if(i, str.end(), space);
		ret.push_back(string(i, j));

		i = j;
	}
	
	return ret;
}


static void print_string(const string& str)
{
	cout << str << endl;
	return;
}

int main()
{
	string str;
	
	getline(cin, str);
	
	vector<string> result = split(str);

	for_each(result.begin(), result.end(), print_string);

	return 0;
}
