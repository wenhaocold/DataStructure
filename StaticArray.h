/*************************************************
Copyright:      wenhaocold
Author:         wenhaocold
Date:           2017/11/6
Description:    实现了静态数组类模板
**************************************************/


#ifndef __STATICARRAY_H__
#define __STATICARRAY_H__

#include "Array.h"

namespace WHLib
{
    template <typename T, int N>
    class StaticArray : public Array<T>
    {
    private:
        T _array[N];

    public:
        StaticArray<T, N>()
        {
            this->_memory = _array;
        }

        StaticArray<T, N>(const StaticArray<T, N>& obj)
        {
            for (int i = 0; i < N; i++)
            {
                _array[i] = obj._array[i];
            }
            this->_memory = _array;
        }

        StaticArray<T, N>& operator = (const StaticArray<T, N>& obj)
        {
            if (this != &obj)
            {
                for (int i = 0; i < N; i++)
                {
                    _array[i] = obj._array[i];
                }
            }
            return *this;
        };


        virtual int length() const override
        {
            return N;
        }
    };
}

#endif //__STATICARRAY_H__
