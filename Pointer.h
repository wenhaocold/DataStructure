//
// Created by 冷文昊 on 2017/12/4.
//

#ifndef __POINTER_H__
#define __POINTER_H__

#include "Object.h"

namespace WHLib {
    template <typename T>
    class Pointer : public Object
    {
    protected:
        T* _pointer;

    public:
        Pointer(T* p = nullptr): _pointer(p) {}

        T* operator ->()
        {
            return _pointer;
        }

        T&operator *()
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
            return *this->_pointer;
        }

        bool isNull()
        {
            return _pointer == nullptr;
        }
    };
}

#endif //__POINTER_H__
