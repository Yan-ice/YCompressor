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
        cursor = begin;
        end = begin+size;

    }

    char_buffer::~char_buffer(){
        delete [] begin;
    }
    /**
     * 将新的元素插入头光标，然后将头光标向后移一位。
     * 如果头光标后移碰到了尾光标，则尾光标也将后移一位。
     * @param ch 将插入的元素
     */
    char char_buffer::push(char ch){
        *cursor = ch;

        cursor++;
        if(cursor==end){
            cursor = begin;
        }
        if(cursor==tail){
            tail++;
        }
        return ch;
    }

    /**
     * 以尾光标位置为基准，获得指定下标的元素。
     * 如果下标为正，则为光标后移，负则前移。
     * 如果下标为0，则返回光标本身。
     * @param offset 与光标的相对位置
     * @return 指定位置的字符指针
     */
    char char_buffer::getTail(int offset){
        char* target = tail;
        if(offset == 0){
            return *tail;
        }
        if(offset > 0){
            while(offset > 0){
                target++;
                if(target==end){
                    target = begin;
                }
                offset--;
            }
        }else{
            while(offset < 0){
                target--;
                if(target==begin-1){
                    target = end-1;
                }
                offset++;
            }
        }
        return *target;
    }
/**
 * 以头光标位置为基准，获得指定下标的元素。
 * 如果下标为正，则为光标后移，负则前移。
 * 如果下标为0，则返回光标本身。
 * @param offset 与光标的相对位置
 * @return 指定位置的字符指针
 */
char char_buffer::getCursor(int offset){
    char* target = cursor;
    if(offset == 0){
        return *cursor;
    }
    if(offset > 0){
        while(offset > 0){
            target++;
            if(target==end){
                target = begin;
            }
            offset--;
        }
    }else{
        while(offset < 0){
            target--;
            if(target==begin-1){
                target = end-1;
            }
            offset++;
        }
    }
    return *target;
}