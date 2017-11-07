/*************************************************
Copyright:      wenhaocold
Author:         wenhaocold
Date:           2017/11/6
Description:    实现了动态数组类模板
**************************************************/


#ifndef __DYNAMICARRAY_H__
#define __DYNAMICARRAY_H__

#include "Array.h"

namespace WHLib
{
    template <typename T>
    class DynamicArray : public Array<T>
    {
    private:
        T* _array;
        int _length;

    public:

        DynamicArray<T>(int size)
        {
            _array = new T[size];
            this->_memory = _array;
            _length = size;
        }

        DynamicArray<T>(const DynamicArray<T>& obj)
        {
            _length = obj.length();
            _array = new T[_length];
            for (int i = 0; i < _length; i++)
            {
                _array[i] = obj._array[i];
                this->_memory = _array;
            }
        }

        DynamicArray<T>& operator =(const DynamicArray<T>& obj)
        {
            if (this != &obj)
            {
                _length = obj.length();
                T* toDel = _array;
                _array = new T[_length];
                for (int i = 0; i < _length; i++)
                {
                    _array[i] = obj._array[i];
                }
                this->_memory = _array;
                delete toDel;
            }
            return *this;
        }

        bool resize(int size)
        {
            T* toDel = _array;
            _array = new T[size];
            if (_array == nullptr)
            {
                return false;
            }
            int count = size < _length ? size : _length;
            _length = size;
            for (int i = 0; i < count; i++)
            {
                _array[i] = toDel[i];
            }
            this->_memory = _array;
            delete toDel;
            return true;
        }

        virtual int length() const override
        {
            return _length;
        }
    };
}

#endif //__DYNAMICARRAY_H__
