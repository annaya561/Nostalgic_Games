#include <bits\stdc++.h>
using namespace std;

/************************************* class ***********************************/
class compute
{
private:
    double first, second, quotient;

public:
    void read(string, string);
    void division();
    bool isNum(string);
};
/********************************** functions **********************************/
bool compute::isNum(string x)
{
    for (int i = 0; i < x.length(); i++)
    {
        if (isdigit(x[i]) == false)
            return false;
    }
    return true;
}
//function to check whether input is double type or not

void compute ::read(string a, string b)
{
    // cout << "read " << a << " " << b;
    try
    {
        if (isNum(a) != 1)
            throw a;
        else if (isNum(b) != 1)
            throw b;
        else
        {
            stringstream obj, obj2;
            obj << a;
            obj >> first;
            obj2 << b;
            obj2 >> second;
            division();
        }
    }
    catch (string s)
    {
        cout << "Wrong input! You entered '" << s << "' which is not a double type." << endl;
    }
    catch (...)
    {
        cout << "default exception";
    }
}
void compute ::division()
{
    try
    {
        if (second == 0)
            throw second;
        else
        {
            quotient = first / second;
            cout << quotient << endl;
        }
    }
    catch (double a)
    {
        cout << "You are dividng the number by 0, which is not posible.\n";
    }
}
/********************************* main **********************************/
int main()
{
    
    compute obj;
    string x, y;
    cout << "Enter numbers you want to compute.\n";
    cin >> x >> y;
    obj.read(x, y);

    return 0;
}