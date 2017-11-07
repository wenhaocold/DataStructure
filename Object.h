//
// Created by 冷文昊 on 2017/11/2.
//

#ifndef DATASTRUCTUREGIT_OBJECT_H
#define DATASTRUCTUREGIT_OBJECT_H

namespace WHLib
{
    class Object
    {
    public:
        void* operator new(unsigned long size) throw();
        void operator delete(void* p);
        void* operator new[](unsigned long size) throw();
        void operator delete[](void* p);

        virtual ~Object() = 0;
    };
}


#endif //DATASTRUCTUREGIT_OBJECT_H
