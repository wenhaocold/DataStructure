//
// Created by 冷文昊 on 2017/11/6.
//

#ifndef __STATIC_LINK_LIST_H__
#define __STATIC_LINK_LIST_H__

#include "LinkList.h"
#include "Exception.h"

namespace WHLib
{
    template <typename T, int N>
    class StaticLinkList : public LinkList<T>
    {
        typedef typename LinkList<T>::Node Node;
    private:
        Node _memory[N];
        char _map[N];
    public:

        StaticLinkList<T, N>()
        {
            for (int i = 0; i < N; i++)
            {
                _map[i] = 0;
            }
        }

        struct SNode : public Node
        {
        public:
            void* operator new(unsigned long size, void* p)
            {
                return p;
            }
        };



        virtual Node* createNode() override
        {
            for (int i = 0; i < N; i++)
            {
                if (_map[i] == 0)
                {
                    Node* ret = reinterpret_cast<Node*>(new(&_memory[i])SNode);
                    _map[i] = 1;
                    return ret;
                }
            }

            THROW_EXCEPTION(Exception, "no enough space to load new Node");
        }

        virtual void destroy(Node* p) override
        {
            int index = (p - _memory) / sizeof(Node);
            int flag = (p - _memory) % sizeof(Node);

            if (index >= 0 && index < N && flag == 0)
            {
                _map[index] = 0;
            }
        }
    };
}

#endif //__STATIC_LINK_LIST_H__
