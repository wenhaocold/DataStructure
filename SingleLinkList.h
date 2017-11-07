//
// Created by 冷文昊 on 2017/11/6.
//

#ifndef __SINGLE_LINK_LIST_H__
#define __SINGLE_LINK_LIST_H__

#include "LinkList.h"

namespace WHLib
{
    template <typename T>
    class SingleLinkList : public LinkList<T>
    {
        typedef typename LinkList<T>::Node  Node;
    protected:
        virtual Node* createNode() override
        {
            return new Node;
        }

        virtual void destroy(Node* p) override
        {
            delete p;
        }
    };
}
#endif //__SINGLE_LINK_LIST_H__
