#include <bits\stdc++.h>
using namespace std;
class base
{
private:
    int a, b;
    string s;

public:
    base(int, int, string);
    void func();
};
base ::base(int x, int y, string st)
{
    a = x;
    b = y;
    s = st;
}
void base::func()
{
    try
    {
        cout << "In try block of func().\n";

        if ((a + b) % 10 == 0)
        {
            cout << "Throwing exception if the sum of two numbers is divisible by 10.\n";
            double q;
            q = (double)(a + b) / 10;
            throw q;
        }
        else if ((a + b) % 11 == 0)
        {
            int q;
            q = (a + b) / 11;
            base obj1(0, 0, "default");
            throw obj1;
            throw q;
        }
        else
            throw s;
    }
    catch (double a)
    {
        cout << "After dividing the number by 10, the quotient is " << a << endl;
        throw;
    }
    catch (int a)
    {
        cout << "After dividing the number by 11, the quotient is " << a << endl;
        throw s;
    }
    catch (base obj)
    {
        cout << "Object exception in func() " << obj.a << " " << obj.b << " " << obj.s << endl;
        throw;
    }
    catch (...)
    {
        cout << "Default exception.\n";
    }
}
int main()
{
    int a, b;
    string s;
    cout << "Enter two numbers and string respectively.\n";
    cin >> a >> b >> s;
    base obj(a, b, s);
    try
    {
        cout << "In try block of main.\n";
        obj.func();
    }
    catch (double q)
    {
        cout << "In catch block of main.\n";
    }
    catch (base obj)
    {
        cout << "Object exception in catch block of main." << endl;
    }
    catch (...)
    {
        cout << "Default exception.\n";
    }

    return 0;
}