//
// Created by 冷文昊 on 2017/11/2.
//

#include "Object.h"
#include <stdlib.h>

namespace WHLib
{
    void* Object::operator new(unsigned long size) throw()
    {
        return malloc(size);
    }
    void Object::operator delete(void* p)
    {
        free(p);
    }
    void* Object::operator new[](unsigned long size) throw()
    {
        return malloc(size);
    }
    void Object::operator delete[](void* p)
    {
        free(p);
    }

    Object::~Object() {

    }
}