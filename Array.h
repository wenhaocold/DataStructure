/*************************************************
Copyright:      wenhaocold
Author:         wenhaocold
Date:           2017/11/6
Description:    实现了数组的抽象父类
**************************************************/

#ifndef __ARRAY_H__
#define __ARRAY_H__

#include "Object.h"
#include "Exception.h"

namespace WHLib
{
    template <typename T>
    class Array : public Object
    {
    protected:
        T* _memory;

    public:
        virtual int length() const = 0;

        T& operator [](int pos)
        {
            if (pos >= 0 && pos < length())
            {
                return _memory[pos];
            }
            else
            {
                THROW_EXCEPTION(Exception, "the index of array is invalid");
            }
        }

        T operator [](int pos) const
        {
            const_cast<Array<T>&>(*this)[pos];
        }


    };
}

#endif //__ARRAY_H__
