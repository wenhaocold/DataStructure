//
// Created by 冷文昊 on 2017/11/2.
//

#ifndef __LIST_H__
#define __LIST_H__
#include "Object.h"

namespace WHLib
{
    template <typename T>
    class List : public Object
    {
    private:
        List(const List&);
        List& operator = (const List&);
    public:
        List(){}
        virtual bool insert(int pos, const T& obj) = 0;
        virtual bool remove(int pos) = 0;
        virtual bool set(int pos, const T& obj) = 0;
        virtual bool get(int pos, T& obj) const = 0;
        virtual int find(const T& obj) = 0;
        virtual int length() const = 0;
        virtual void clear() = 0;
    };
}
#endif //__LIST_H__
