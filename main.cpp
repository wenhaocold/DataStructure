#include <iostream>
#include "SingleLinkList.h"
#include "SmartPointer.h"
#include "SharedPointer.h"

using namespace std;
using namespace WHLib;

class Test {

public:
    int _value;
    Test(int value): _value(value) {
        cout << "Test()" << endl;
    }

    ~Test() {
        cout << "~Test()" << endl;
    }
};

int main()
{
    SharedPointer<Test> sp1 = new Test(9);
    SharedPointer<Test> sp2 = sp1;
    SharedPointer<Test> sp3 = nullptr;

    sp3 = sp2;
    cout << sp1->_value << endl;
    cout << sp2->_value << endl;;
    cout << sp3->_value << endl;;

    return 0;
}