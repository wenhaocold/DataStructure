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
        cl.next(step - 1);
        int temp = cl.currentNode()->_value;
        cl.remove(cl.find(cl.currentNode()->_value));
        cout << "kill: " << temp << endl;
    }
}


int main()
{
     test(10, 3);
//    CircleLinkList<int> cl;
//    for (int i = 0; i < 5; i++) {
//        cl.insert(i, i);
//    }
////    cl.begin();
//    cl.remove(0);
//    cl.remove(0);
//    cl.remove(0);
//    cl.remove(0);
//    cl.remove(0);


    return 0;

}