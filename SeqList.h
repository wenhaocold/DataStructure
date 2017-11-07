/*************************************************
Copyright:      wenhaocold
Author:         wenhaocold
Date:           2017/11/2
Description:    实现了线性表的抽象父类
**************************************************/

#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include "List.h"
#include "Exception.h"

namespace WHLib
{
    template <typename T>
    class SeqList : public List<T>
    {
    protected:
        T* _memory;
        int _length;
    public:
        SeqList<T>()
        {
            _length = 0;
            _memory = nullptr;
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
            // 判断插入的位置是否正确
            bool ret = (pos >=0 && pos <= _length && pos < capacity());
            if (ret)
            {
                for (int i = _length; i > pos; i--)
                {
                    _memory[i] = _memory[i - 1];
                }
                _memory[pos] = obj;
                _length++;
            }
            else
            {
                THROW_EXCEPTION(Exception, "the index of the list is invalid");
            }
            return ret;
        }

        /*
         * Fun: remove(int pos)
         * Des: 从线性表中删除一个元素
         * Arg1: pos: 将要从线性表中删除元素的位置
         * Ret: 成功返回true,失败返回false
         */
        virtual bool remove(int pos) override
        {
            // 判断删除的位置是否正确
            bool ret = (pos >=0 && pos < _length);
            if (ret)
            {
                for (int i = pos; i < _length; i++)
                {
                    _memory[i] = _memory[i + 1];
                }
                _length--;
            }
            else
            {
                THROW_EXCEPTION(Exception, "the index of the list is invalid");
            }
            return ret;
        }

        /*
         * Fun: set(int pos, const T& obj)
         * Des: 改变线性表中某个位置上的元素
         * Arg1: pos: 将要改变的线性表中元素的位置
         * Arg2: obj: 将要改变的值
         * Ret: 成功返回true,失败返回false
         */
        virtual bool set(int pos, const T& obj) override
        {
            // 判断改变的位置是否正确
            bool ret = (pos >=0 && pos < _length);
            if (ret)
            {
               _memory[pos] = obj;
            }
            else
            {
                THROW_EXCEPTION(Exception, "the index of the list is invalid");
            }
            return ret;
        }

        /*
         * Fun: get(int pos, T& obj)
         * Des: 获取线性表中某个位置的元素的值
         * Arg1: pos: 线性表中的位置
         * Arg2: obj: 用来保存获取的这个元素的值
         * Ret: 成功返回true,失败返回false
         */
        virtual bool get(int pos, T& obj) const override
        {
            // 判断位置是否正确
            bool ret = (pos >=0 && pos < _length);
            if (ret)
            {
                obj = _memory[pos];
            }
            else
            {
                THROW_EXCEPTION(Exception, "the index of the list is invalid");
            }
            return ret;
        }

        T& operator [](int pos)
        {
            bool ret = (pos >=0 && pos < _length);
            if (ret)
            {
                return _memory[pos];
            }
            else
            {
                THROW_EXCEPTION(Exception, "the index of the list is invalid");
            }
        }

        T operator [](int pos) const
        {
            const_cast<SeqList<T>&>(*this)[pos];
        }

        /*
         * Fun: fin(const T& obj)
         * Des: 查找某个元素在线性表中的位置（注：若存在相同的两个元素，那么
         * 将只会查找出第一个元素）
         * Arg1: obj: 待查找的元素
         * Ret: 成功则返回元素所在的位置，失败返回-1;
         * Note: 因为这里使用了==操作符，所以需要表中的元素支持==操作符
         */
        virtual int find(const T& obj) override
        {
            int ret = -1;
            for (int i = 0; i < _length; i++)
            {
                if (_memory[i] == obj)
                {
                    ret = i;
                    break;
                }
            }
            return ret;
        }

        /*
         * Fun: length()
         * Des: 得到该线性表目前的长度
         * Arg: None
         * Ret: 线性表的长度
         */
        virtual int length() const override
        {
            return _length;
        }

        /*
         * Fun: clear()
         * Des: 清空线性表
         * Arg: None
         * Ret: None
         */
        virtual void clear() override
        {
            _length = 0;
        }

        /*
         * Fun: capacity()
         * Des: 返回线性表的最大容量
         * Arg: None
         * Ret: 线性表的最大容量
         */
        virtual int capacity() const = 0;
    };
}
#endif //__SEQLIST_H__
