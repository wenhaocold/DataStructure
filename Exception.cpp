//
// Created by 冷文昊 on 2017/11/2.
//

#include "Exception.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

namespace WHLib
{
    void Exception::ExceptionHelper(const char* file, const int line, const char* msg)
    {
        _msg = nullptr;
        _location = nullptr;
        if (msg != nullptr)
            _msg = strdup(msg);

        if (file != nullptr) {
            char l[20];
            sprintf(l, "%d", line);
            _location = (char *) malloc(strlen(file) + strlen(l) + 2);
            strcpy(_location, file);
            strcat(_location, ":");
            strcat(_location, l);
        }

    }

    Exception::Exception(const char* file, const int line, const char* msg)
    {
        ExceptionHelper(file, line, msg);
    }
    Exception::Exception(const char* file, const int line)
    {
        ExceptionHelper(file, line, nullptr);
    }
    Exception::Exception(const char* msg)
    {
        ExceptionHelper(nullptr, 0, msg);
    }

    Exception::Exception(const Exception& obj)
    {
        if (obj._location != nullptr) {
            _location = strdup(obj._location);
        }
        else
        {
            _location = nullptr;
        }
        if (obj._msg != nullptr) {
            _msg = strdup(obj._msg);
        }
        else
        {
            _msg = nullptr;
        }
    }

    const char* Exception::location() const
    {
        return _location;
    }
    const char* Exception::msg() const
    {
        return _msg;
    }

    Exception::~Exception()
    {
        delete _location;
        delete _msg;
    }
}