//
// Created by 颜嘉钦 on 9/14/21.
//
#include <iostream>
#include <fstream>
#include "yjq_compressor.h"
#include "char_buffer.h"

using namespace std;

ifstream in = ifstream();
//从文件读取信息

ofstream out = ofstream();
//向文件写入信息

char replace_space = '^';
char replace_endl = '%';

/**
 * 将源文件指定长度字符压缩，并输出到文件。
 * @param begin 字符串首
 * @param end 字符串尾
 * @param buffer_length 缓冲区长度
 */
void compress(char sourceFileName[],char targetFileName[],int buffer_length, int package_length){
    in.open(sourceFileName,ios::out | ios::in);
    out.open(targetFileName,ios::out | ios::in);

    in.seekg(0,in.end);
    package_length = in.tellg();
    in.seekg(0,in.beg);
    cout<<"待压缩文件总长度： "<<package_length<<endl;

    char begin[package_length];
    char *end = begin;
    for(int a = 0;a<package_length;a++){
        *end = in.get();
        end++;
    }
    char *cursor = begin;
    while(cursor<end){
        OLC olc;
        if(cursor-begin<buffer_length){
            olc = check_length(begin,cursor);
        }else{
            olc = check_length(cursor-buffer_length,cursor);
        }
        cursor = olc.next+1;
        if(olc.next>=end){
            out<<olc.offset<<" "<<olc.length<<" "<<'\0'<<endl;
        }else{
            char t = *(olc.next);
            if(t=='\n'){
                t=replace_endl;
            }else if(t==' '){
                t=replace_space;
            }
            out<<olc.offset<<" "<<olc.length<<" "<<t<<endl;
        }
    }
    in.close();
    out.close();
}

/**
 * 寻找最大匹配字符串，并返回olc。
 * @param L_begin 字典缓冲区header
 * @param R_begin 先行缓冲区header
 * @return olc
 */
OLC check_length(char *L_begin, char *R_begin){
    int dic_size = R_begin-L_begin;
    OLC olc;
    olc.next = R_begin;
    for(int offset = 0;offset<dic_size;offset++){
        char *i = L_begin+offset;
        char *j = R_begin;
        int count = 0;
        while(*i==*j){
            i++;j++;
            count++;
        }
        if(count>olc.length){
            olc.length = count;
            olc.offset = offset;
            olc.next = j;
        }
    }
    return olc;
}

/**
 * 输入字符，解压到另一个文件。
 * @param buffer_length
 */
void decompress(char sourceFileName[],char targetFileName[],int buffer_length) {
    in.open(sourceFileName,ios::out | ios::in);
    out.open(targetFileName,ios::out | ios::in);
    char_buffer buffer = char_buffer(buffer_length+1);

    int offset, length;
    char next;
    while (in >> offset >> length >> next) {
        if (length == 0) {
            if(next==replace_endl){
                out<<buffer.push('\n');
            }else if(next==replace_space) {
                out << buffer.push(' ');
            }else{
                out<<buffer.push(next);
            }
            continue;
        }
        //无匹配字符直接打印
        char* beg = buffer.getTail(offset);
        for (int a = 0; a < length; a++) {
            out<<buffer.push(*beg);
            beg = buffer.next(beg);
        }

        if (next != '\0') {
            if(next==replace_endl){
                out<<buffer.push('\n');
            }else if(next==replace_space) {
                out << buffer.push(' ');
            }else{
                out<<buffer.push(next);
            }
        } else {
            break;
        }
        //打印匹配字符串与下一个字符
    }
    in.close();
    out.close();
}