/*************************************************
Copyright:      wenhaocold
Author:         wenhaocold
Date:           2017/11/2
Description:    实现了动态线性表的功能
**************************************************/

#ifndef __DYNAMICSEQLIST_H__
#define __DYNAMICSEQLIST_H__

#include "SeqList.h"

namespace WHLib
{
    template <typename T>
    class DynamicSeqList : public SeqList<T>
    {
    private:
        int _capacity;

    public:
        DynamicSeqList<T>(int capacity)
        {
            _capacity = capacity;
            this->_memory = new T[_capacity];
        }

        virtual int capacity() const override
        {
            return _capacity;
        }

        bool resize(int size)
        {
            _capacity = size;
            T* toDel = this->_memory;
            this->_memory = new T[size];
            if (this->_memory == nullptr)
                return false;

            this->_length = this->_length < size ? this->_length : size;
            for (int i = 0; i < this->_length; i++)
            {
                this->_memory[i] = toDel[i];
            }
            delete toDel;
            return true;
        }

        ~DynamicSeqList<T>()
        {
            delete[] this->_memory;
        }
    };
}

#endif //__DYNAMICSEQLIST_H__
