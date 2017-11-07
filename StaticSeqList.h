/*************************************************
Copyright:      wenhaocold
Author:         wenhaocold
Date:           2017/11/2
Description:    实现了静态线性表
**************************************************/

#ifndef __STATICSEQLIST_H__
#define __STATICSEQLIST_H__

#include "SeqList.h"

namespace WHLib
{
    template <typename T, int N>
    class StaticSeqList : public SeqList<T>
    {
    private:
        T _array[N];

    public:
        StaticSeqList<T>()
        {
            this->_memory = _array;
        }

        virtual int capacity() const override
        {
            return N;
        }
    };
}

#endif //__STATICSEQLIST_H__
