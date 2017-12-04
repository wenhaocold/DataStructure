#include <iostream>
#include "SingleLinkList.h"

using namespace std;
using namespace WHLib;

int main()
{
    SingleLinkList<int> ll;

    for (int i = 0; i < 5; i++)
    {
        ll.insert(i, i);
    }

    for (ll.begin(); !ll.end(); ll.next())
    {
        cout << ll.currentNode()->_value << endl;

    }
}