#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

void print_str(const std::string &s) 
{
        std::cout << s << std::endl;
}

int main()
{
        std::cout << "Please enter your  first name: ";

        std::string name;
        std::cin >> name;

        const std::string greeting = "Hello, " + name + "!";

        const int pad = 3;
        const std::string::size_type cols = greeting.size() + pad * 2 + 2;

        const std::string first(cols, '*');
        const std::string spaces(greeting.size() + pad * 2, ' ');
        const std::string second = '*' + spaces + '*';
        const std::string middle = '*' + std::string(pad, ' ') + greeting + std::string(pad, ' ') + '*';

        std::vector<std::string> lines;

        lines.push_back(first);
        for(int i = 0; i != pad; i++)
                lines.push_back(second);
        lines.push_back(middle);
        for(int i = 0; i != pad; i++)
                lines.push_back(second);
        lines.push_back(first);

        std::for_each(lines.begin(), lines.end(), print_str);

        return 0;
}
