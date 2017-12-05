#include <iostream>
#include "SingleLinkList.h"
#include "SmartPointer.h"
#include "SharedPointer.h"
#include "CircleLinkList.h"


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

void test(int num, int step) {
    CircleLinkList<int> cl;

    for (int i = 0; i < num; i++) {
        cl.insert(i, i + 1);
    }

    cl.begin(0);

    while (!cl.end()) {
//        cl.next()
    }
}


int main()
{
    CircleLinkList<int> cl;

    for (int i = 0; i < 5; i++) {
        cl.insert(i, i);
    }


    cl.remove(2);

    return 0;
}