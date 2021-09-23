//
// Created by 颜嘉钦 on 9/14/21.
//
#include <iostream>
#include "../header/char_buffer.h"

    /**
     * 建立一个环形数组。
     * @param size 环的大小
     */
    char_buffer::char_buffer(int size){
        begin = new char[size];
        end = begin+size;
        for(char *p = begin;p!=end;p++){
            *p = '1';
        }

        cursor = begin;
        tail = begin;
    }

    char_buffer::~char_buffer(){
        delete [] begin;
    }

    /**
     * 将新的元素插入头光标，然后将头光标向后移一位。
     * 如果头光标后移碰到了尾光标，则尾光标也将后移一位。
     * (单纯为了图个方便，)该方法还会返回插入元素的地址。
     * @param ch 将插入的元素
     */
    char char_buffer::push(char ch){
        *cursor = ch;
        next(cursor);
        if(cursor==tail){
            next(tail);
        }
        return ch;
    }

/**
 * 将新的元素追加到尾光标，然后将尾光标向后移一位。
 * 如果尾光标碰到头光标，则返回false，否则返回true。
 */
bool char_buffer::add(char ch){
    *tail = ch;
    next(tail);
    if(cursor==tail){
        return false;
    }
    return true;
}
    /**
     * 以尾光标位置为基准，获得指定下标的元素。
     * 如果下标为正，则为光标后移，负则前移。
     * 如果下标为0，则返回光标本身。
     * @param offset 与光标的相对位置
     * @return 指定位置的字符指针
     */
    char* char_buffer::getTail(int offset){
        char* target = tail;
        if(offset == 0){
            return tail;
        }
        if(offset > 0){
            while(offset > 0){
                next(target);
                offset--;
            }
        }else{
            while(offset < 0){
                last(target);
                offset++;
            }
        }
        return target;
    }
/**
 * 以头光标位置为基准，获得指定下标的元素。如果下标为正，则为光标后移，负则前移。
 * 如果下标为0，则返回光标本身。
 * @param offset 与光标的相对位置
 */
char* char_buffer::getCursor(int offset){
    char* target = cursor;
    if(offset == 0){
        return cursor;
    }
    if(offset > 0){
        while(offset > 0){
            next(target);
            offset--;
        }
    }else{
        while(offset < 0){
            last(target);
            offset++;
        }
    }
    return target;
}

/**
 * 获得p在环数组中的下一个指针。
 * @param p
 * @return
 */
char* char_buffer::next(char *&p){
    p++;
    if(p>=end){
        p = begin;
        return p;
    }
    return p;
}

/**
 * 获得p在环数组中的上一个指针。
 * @param p
 * @return
 */
char* char_buffer::last(char *&p){
    p--;
    if(p<begin){
        p = end-1;
    }
    return p;
}

void char_buffer::moveCursor(int offset){
    if(offset > 0){
        while(offset > 0){
            next(cursor);
            offset--;
        }
    }else{
        while(offset < 0){
            last(cursor);
            offset++;
        }
    }
}

void char_buffer::print(){
    printf("数组首部地址%p 数组尾部地址%p\n",begin,end);
    std::cout<<"数组内容: ";
    for(char* p = begin;p!=end;p++){
        std::cout<<*p;
    }
    std::cout<<std::endl;

    //std::cout<<begin<<std::endl;
}