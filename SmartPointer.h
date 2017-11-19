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

        explicit SmartPointer<T>(T* pointer) :
                _pointer(pointer)
        {

        }

        //在调用赋值构造函数的时候转移指针的所有权
        SmartPointer<T>(const SmartPointer<T>& obj)
        {
            _pointer = obj._pointer;
            const_cast<SmartPointer<T>&>(obj)._pointer = nullptr;
        }

        //在调用赋值操作符的时候转移指针的所有权
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

        //这里等价于: T operator *(const SmartPointer<T> this);
        //所以const成员函数其实是上述函数的缩写，所以const对象只能够调用
        //const成员函数。又因为函数参数不同，所以const成员函数是非const
        // 成员函数的重载。
        // 如果用户将智能指针定义为const类型，那么表明用户不想改变指针指向
        // 的内容的值，所以这里我们返回一个值，而不是引用。
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
