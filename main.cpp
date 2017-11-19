#include <iostream>
#include "SmartPointer.h"


using namespace std;
using namespace WHLib;

class Test
{
public:
    Test()
    {
        cout << "Test()" << endl;
    }
    Test(const Test&)
    {
        cout << "Test(cosnt Test&)" << endl;
    }

    Test& operator = (const Test& obj)
    {
        cout << "operator =" << endl;
        return *this;
    }

    ~Test()
    {
        cout << "~Test()" << endl;
    }

    bool operator == (const Test& t)
    {
        return true;
    }

};

int main()
{
    int a = 0;
     SmartPointer<int> p(&a);
    *p = 99;
    cout << "a = " << a << endl;
}