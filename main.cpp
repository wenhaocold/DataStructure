#include <iostream>
#include "SingleLinkList.h"
#include "SmartPointer.h"

using namespace std;
using namespace WHLib;

class Test {

public:
    Test() {
        cout << "Test()" << endl;
    }

    ~Test() {
        cout << "~Test()" << endl;
    }
};

int main()
{
    SmartPointer<Test> t = new Test;

    cout << "=======" << endl;
}