//
// Created by 冷文昊 on 2018/3/1.
//

#ifndef _OBSERVERPATTERN_H_
#define _OBSERVERPATTERN_H_

#include <map>
#include <list>
#include <string>



class Subject;
typedef void (*CALL_BACK) (const std::string& str, Subject* observer);
class Observer
{
private:

public:
    CALL_BACK _callBack;
    virtual void update(const std::string& str, Subject* observer) = 0;
};

class Subject
{
private:
    std::map<std::string, std::list<Observer*>> _observer;

public:
    void attach(const std::string& str, Observer* observer, CALL_BACK callBack)
    {
        observer->_callBack = callBack;
        _observer[str].push_back(observer);
    }

    void notiffy(const std::string& str)
    {
        for (auto iter = _observer[str].begin(); iter != _observer[str].end(); ++iter)
        {
            (*iter)->_callBack(str, this);
        }
    }
};


#endif //_OBSERVERPATTERN_H_
