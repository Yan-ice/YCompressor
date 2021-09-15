//
// Created by 颜嘉钦 on 9/14/21.
//
#include <iostream>
#include "char_buffer.h"

    /**
     * 建立一个环形数组作为缓冲区。
     * @param size 环的大小
     */
    char_buffer::char_buffer(int size){
        begin = new char[size];
        cursor = &begin[0];
        tail = cursor;
        end = cursor+size;
        for(char *p = begin;p!=end;p++){
            *p = '\0';
        }
    }

    char_buffer::~char_buffer(){
        delete [] begin;
    }
    /**
     * 将新的元素插入头光标，然后将头光标向后移一位。
     * 如果头光标后移碰到了尾光标，则尾光标也将后移一位。
     * 该方法还会返回插入元素的地址。
     * @param ch 将插入的元素
     */
    char char_buffer::push(char ch){
        *cursor = ch;
        cursor = next(cursor);
        if(cursor==tail){
            tail = next(tail);
        }
        return ch;
    }

/**
 * 将新的元素追加到尾光标，然后将尾光标向后移一位。
 * 如果尾光标碰到头光标，则返回false，否则返回true。
 */
bool char_buffer::add(char ch){
    *tail = ch;
    tail = next(tail);
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
                target = next(target);
                offset--;
            }
        }else{
            while(offset < 0){
                target = last(target);
                offset++;
            }
        }
        return target;
    }
/**
 * 以头光标位置为基准，获得指定下标的元素。
 * 如果下标为正，则为光标后移，负则前移。
 * 如果下标为0，则返回光标本身。
 * @param offset 与光标的相对位置
 * @return 指定位置的字符指针
 */
char* char_buffer::getCursor(int offset){
    char* target = cursor;
    if(offset == 0){
        return cursor;
    }
    if(offset > 0){
        while(offset > 0){
            target = next(target);
            offset--;
        }
    }else{
        while(offset < 0){
            target = last(target);

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
char* char_buffer::next(char* p){
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
char* char_buffer::last(char* p){
    p--;
    if(p<begin){
        p = end-1;
    }
    return p;
}

void char_buffer::moveCursor(int offset){
    if(offset > 0){
        while(offset > 0){
            cursor = next(cursor);
            offset--;
        }
    }else{
        while(offset < 0){
            cursor = last(cursor);
            offset++;
        }
    }
}