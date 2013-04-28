#include <string>
#include <cctype>
#include <algorithm>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::isalnum;
using std::find_if;
using std::cin;
using std::cout;
using std::getline;
using std::endl;

typedef string::const_iterator iter;

bool not_url_char(char c)
{
	static const string url_chars = "~;/?:@=&$-_.+!*'(),";
	return !(isalnum(c) || 
		 (find(url_chars.begin(), url_chars.end(), c) != url_chars.end()));
}

iter url_end(iter b, iter e)
{
	return find_if(b, e, not_url_char);
}

iter url_begin(iter b, iter e)
{
	static const string sep = "://";
	
	iter i = b;
	
	while ((i = ))
}

vector<string> find_urls(const string& str)
{
	vector<string> ret;
	
	
	iter b = str.begin(), e = str.end();

	while(b != e) {
		
		b = url_begin(b, e);
		if (b == e) break;

		iter after = url_end(b, e);
		ret.push_back(string(b, after));

		b = after;
	}
	
	return ret;
}
