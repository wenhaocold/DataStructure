//
// Created by 冷文昊 on 2017/12/4.
//

#ifndef __SHAREDPOINTER_H__
#define __SHAREDPOINTER_H__

#include "Pointer.h"
#include <cstdlib>
#include "Exception.h"
namespace WHLib {
    template <typename T>
    class SharedPointer: public Pointer<T>
    {
    private:
        int* _ref;

    public:
        SharedPointer(T* pointer) : Pointer<T>(pointer) {
            if (pointer) {
                _ref = static_cast<int*>(malloc(sizeof(int)));
                if (_ref) {
                    this->_pointer = pointer;
                    (*_ref) = 1;
                }
                else {
                    THROW_EXCEPTION(Exception, "malloc memory fail");
                }
            } else {
                _ref = nullptr;
            }
        }

        SharedPointer(const SharedPointer& obj) {
            _ref = obj._ref;
            this->_pointer = obj._pointer;
            (*_ref)++;
        }

        SharedPointer<T>& operator=(const SharedPointer<T>& obj) {
            if (this != &obj) {
                // 防止指向同一片堆空间的指针再次相互赋值
                if (this->_pointer != obj._pointer) {
                    clear();
                    _ref = obj._ref;
                    (*_ref)++;
                    this->_pointer = obj._pointer;
                }

            }
            return *this;
        }

        void clear() {
            int* ref = _ref;
            T* toDel = this->_pointer;

            _ref = nullptr;
            this->_pointer = nullptr;

            if (ref)
            {
                (*ref)--;
                if (*ref == 0)
                {
                    free(ref);
                    delete toDel;
                }
            }
        }

        bool operator == (const SharedPointer<T> obj){
            return this->_pointer == obj._pointer;
        }

        bool operator != (const SharedPointer<T> obj) {
            return !(*this == obj);
        }

        ~SharedPointer()
        {
            clear();
        }



    };
}

#endif //__SHAREDPOINTER_H__
