//
// Created by 冷文昊 on 2017/11/2.
//

#ifndef __SMARTPOINTER_H__
#define __SMARTPOINTER_H__
#include "Object.h"

namespace WHLib
{
    template <typename T>
    class SmartPointer: public Object
    {
    private:
        T* _pointer;
    public:

        SmartPointer<T>(T* pointer) :
                _pointer(pointer)
        {

        }

        SmartPointer<T>(const SmartPointer<T>& obj)
        {
            _pointer = obj._pointer;
            const_cast<SmartPointer<T>&>(obj)._pointer = nullptr;
        }


        SmartPointer<T>& operator = (const SmartPointer<T>& obj)
        {
            if (this != &obj)
            {
                _pointer = obj._pointer;
                const_cast<SmartPointer<T>&>(obj)._pointer = nullptr;
            }
        }

        T& operator *()
        {
            return *_pointer;
        }

        T operator *() const
        {
            return *_pointer;
        }

        T* operator ->()
        {
            return _pointer;
        }

        ~SmartPointer<T>()
        {
            delete _pointer;
        }
    };
}

#endif //__SMARTPOINTER_H__
