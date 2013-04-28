#include <string>
#include <iostream>
#include <algorithm>

using std::string;
using std::getline;
using std::cin;
using std::cout;
using std::endl;
using std::equal;

int main()
{
	string str;
	cin >> str;
	
	if (equal(str.begin(), str.end(), str.rbegin()))
		cout << str << " is a palindrome" << endl;
	else 
		cout << str << " is not a palindrome" << endl;

	return 0;
}
