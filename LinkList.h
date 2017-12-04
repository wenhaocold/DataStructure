/*************************************************
Copyright:      wenhaocold
Author:         wenhaocold
Date:           2017/11/6
Description:    实现了链式线性表的抽象父类
**************************************************/

#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include "List.h"
#include "Object.h"
#include "Exception.h"

namespace WHLib
{
    template <typename T>
    class LinkList : public List<T>
    {
    protected:
        struct Node : public Object
        {
            Node* _next;
            T _value;
        };

        mutable struct : public Object
        {
            Node* _next;
            char _placeholder[sizeof(T)];

        }_header;
        int _length;

        Node* getCurrentPre(int pos) const
        {
            Node* currentPre = reinterpret_cast<Node*>(&_header);
            for (int i = 0; i < pos; i++)
            {
                currentPre = currentPre->_next;
            }
            return currentPre;
        }

        virtual Node* createNode() = 0;
        virtual void destroy(Node* p) = 0;

        Node* _currentNode;
        int _step;

    public:

        LinkList<T>()
        {
            _length = 0;
            _step = 1;
            _currentNode = nullptr;
            _header._next = nullptr;
        }

        /*
        * Fun: bool insert(int pos, const T& obj)
        * Des: 在线性表中插入一个元素
        * Arg1: pos: 元素插入的位置
        * Arg2: obj: 待插入的元素
        * Ret: 操作成功返回true,失败返回false;
        */
        virtual bool insert(int pos, const T& obj) override
        {
            bool ret = (pos >= 0 && pos <= _length);
            if (ret)
            {
                //获取将要插入位置的前一个位置
                Node* currentPre = getCurrentPre(pos);
                //将obj插入到指定的位置上
                if (currentPre)
                {
                    Node *newNode = createNode();
                    newNode->_value = obj;
                    newNode->_next = currentPre->_next;
                    currentPre->_next = newNode;
                    _length++;
                }
                else
                {
                    ret = false;
                }
            }
            else
            {
                THROW_EXCEPTION(Exception, "can't insert the obj to the LinkList");
            }
            return ret;
        }
        virtual bool remove(int pos) override
        {
            bool ret = (pos >= 0 && pos < _length);
            if (ret)
            {
                //获取将要删除元素位置的前一个位置
                Node* currentPre = getCurrentPre(pos);
                if (currentPre)
                {
                    Node* toDel = currentPre->_next;
                    currentPre->_next = toDel->_next;
                    _length--;
                    destroy(toDel);
                }
                else
                {
                    ret = false;
                }
            }
            else
            {
                THROW_EXCEPTION(Exception, "the index is invalid");
            }
            return ret;
        }

        virtual bool set(int pos, const T& obj) override
        {
            bool ret = (pos >= 0 && pos < _length);
            if (ret)
            {
                //获取将要设置元素位置的前一个位置
                Node* currentPre = getCurrentPre(pos);
                if (currentPre)
                {
                    currentPre->_next->_value = obj;
                }
                else
                {
                    ret = false;
                }
            }
            else
            {
                THROW_EXCEPTION(Exception, "the index is invalid");
            }
            return ret;
        }

        virtual bool get(int pos, T& obj) const override
        {
            bool ret = (pos >= 0 && pos < _length);
            if (ret)
            {
                //获取将要获取元素位置的前一个位置
                Node* currentPre = getCurrentPre(pos);
                if (currentPre)
                {
                    obj = currentPre->_next->_value ;
                }
                else
                {
                    ret = false;
                }
            }
            else
            {
                THROW_EXCEPTION(Exception, "the index is invalid");
            }
            return ret;
        }

        virtual int find(const T& obj) override
        {
            Node* current = _header._next;
            int i = 0;
            int step = 0;
            //这里使用step'这个标记是为了防止整个链表遍历完毕后
            // 还没有找到指定的元素而出现错误。
            while (current && step++)
            {
                if (current->_value == obj)
                {
                    break;
                }
                current = current->_next;
                i++;
            }

            if (step >= _length)
            {
                return -1;
            }

            return i;
        }

        virtual int length() const override
        {
            return _length;
        }

        virtual void clear() override
        {
            Node* current = _header._next;

            while (current)
            {
                Node* toDel = current;
                current = current->_next;
                _length--;
                destroy(toDel);
            }

            if (_length != 0)
            {
                THROW_EXCEPTION(Exception, "clear LinkList error");
            }
        }

        bool begin(int pos = 0)
        {
            bool ret = (pos >= 0 && pos <_length);
            if (ret) {
                _currentNode = getCurrentPre(pos)->_next;
            }
            return ret;
        }

        void next(int step = 1)
        {
            for (int i = 0; i < step && !end(); i++)
            {
                _currentNode = _currentNode->_next;
            }
        }

        bool end()
        {
            return _currentNode == nullptr;
        }

        Node* currentNode()
        {
            return _currentNode;
        }

    };
}

#endif //__LINKLIST_H__
