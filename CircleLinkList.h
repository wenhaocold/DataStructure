//
// Created by 冷文昊 on 2017/12/5.
//

#ifndef __CIRCLELINKLIST_H__
#define __CIRCLELINKLIST_H__

#include "LinkList.h"
#include "Exception.h"

namespace WHLib {
    template <typename T>
    class CircleLinkList: public LinkList<T> {
        typedef typename LinkList<T>::Node Node;
    private:
        void lastToFirst()
        {
            this->getCurrentPre(this->_length - 1)->_next->_next =
                    this->getCurrentPre(0)->_next;
        }
        void cancleLastToFirst() {
            this->getCurrentPre(this->_length - 1)->_next->_next =
                    nullptr;
        }
        int mod(int pos) const {
            return pos % this->_length;
        }

    public:
        virtual bool insert(int pos, const T& obj) override {
            bool ret = LinkList<T>::insert(pos, obj);
            if (0 == pos) {
                lastToFirst();
            }
            return ret;
        }

        virtual bool remove(int pos) override {
            bool ret = LinkList<T>::remove(pos);
            if (0 == pos) {
                lastToFirst();
            }
            return ret;
        }

        virtual Node* createNode() override {
            return new Node;
        }
        virtual void destroy(Node* p) override {
            delete p;
        }
        virtual bool set(int pos, const T& obj) override {
            return set(mod(pos), obj);
        }
        virtual bool get(int pos, T& obj) const override {
            return get(mod(pos), obj);
        }
        virtual int find(const T& obj) override {
            Node* current = this->_header._next;
            for (int i = 0; i < this->_length; i++) {
                if (obj == current->_value) {
                    return i;
                }
            }
            return -1;
        }
        virtual void clear() override {
            cancleLastToFirst();
            LinkList<T>::clear();
        }
    };


}

#endif //__CIRCLELINKLIST_H__
