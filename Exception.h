//
// Created by 冷文昊 on 2017/11/2.
//

#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__
#include "Object.h"

namespace WHLib
{
    #define THROW_EXCEPTION(e, msg) throw e(msg);
    class Exception: public  Object
    {
    private:
        char* _location;
        char* _msg;
    public:
        void ExceptionHelper(const char* file, const int line, const char* msg);
        Exception(const char* file, const int line, const char* msg);
        Exception(const char* file, const int line);
        Exception(const char* msg);
        Exception(const Exception& obj);
        const char* location() const;
        const char* msg() const;
        ~Exception();
    };
}


#endif //DATASTRUCTUREGIT_EXCEPTION_H
