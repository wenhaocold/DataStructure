#include <iostream>
#include "Object.h"
#include "SmartPointer.h"
#include "Exception.h"
#include "SeqList.h"
#include "StaticSeqList.h"
#include "DynamicSeqList.h"
#include "StaticArray.h"
#include "DynamicArray.h"
#include "LinkList.h"
#include "SingleLinkList.h"
#include "StaticLinkList.h"


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
    StaticLinkList<int, 5> sll;

    for (int i = 0; i < 6; i++)
    {
        sll.insert(i, i);
    }
}