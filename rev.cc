#include <string>
#include <iostream>

using std::string;
using std::getline;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	string str;
	getline(cin, str);
	cout << string(str.rbegin(), str.rend()) << endl;
	return 0;
}
