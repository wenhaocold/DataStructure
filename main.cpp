#include <iostream>
#include "StaticLinkList.h"
#include "SingleLinkList.h"
#include "ObserverPattern.h"

using namespace WHLib;
using namespace std;


class ObserverTest : public Observer
{
private:

public:
    void update(const std::string& str, Subject* observer)
    {
        cout << "Hello ObserverTest" << endl;
    }
};

void update(const std::string& str, Subject* observer)
{
    cout << "Hello ObserverTest" << endl;
}

int main()
{
    ObserverTest    oTest;
    Subject         subject;

    subject.attach("test", &oTest, update);
    subject.notiffy("test");

    cout << "Over" << endl;
    return 0;
}