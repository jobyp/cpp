#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>

int main()
{
        using namespace std;

        cout << "Please enter your first name: ";
        string name;
        cin >> name;
        cout << "Hello, " << name << "!" << endl;
       

        cout << "Please enter your midterm and final exam grades: ";
        double midterm, final;
        cin >> midterm >> final;

        cout << "Please enter all your homework grades, followed by EOF: ";
        double x;

        vector<double> homework(1,0);
        
        while (cin >> x) 
                homework.push_back(x);

        vector<double>::size_type count = homework.size();
        double sum = accumulate(homework.begin(), homework.end(), 0);
        
        streamsize prec = cout.precision();
        cout << "Your final score is " << setprecision(3)
             << 0.2 * midterm + 0.4 * final + 0.4 * sum / count 
             << setprecision(prec) << endl;

        return 0;
}       
