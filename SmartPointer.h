//
// Created by 冷文昊 on 2017/11/2.
//

#ifndef __SMARTPOINTER_H__
#define __SMARTPOINTER_H__
#include "Object.h"
#include "Pointer.h"

namespace WHLib
{
    template <typename T>
    class SmartPointer: public Pointer<T>
    {
    public:

        SmartPointer<T>(T* pointer) : Pointer<T>(pointer){}


        //在调用赋值构造函数的时候转移指针的所有权
        SmartPointer<T>(const SmartPointer<T>& obj)
        {
            this->_pointer = obj._pointer;
            const_cast<SmartPointer<T>&>(obj)._pointer = nullptr;
        }

        //在调用赋值操作符的时候转移指针的所有权
        SmartPointer<T>& operator = (const SmartPointer<T>& obj)
        {
            if (this != &obj)
            {
                T* toDel = this->_pointer;
                this->_pointer = obj._pointer;
                const_cast<SmartPointer<T>&>(obj)._pointer = nullptr;
                delete toDel;
            }
            return *this;
        }

        ~SmartPointer<T>()
        {
            delete this->_pointer;
        }
    };
}

#endif //__SMARTPOINTER_H__
