//
// Created by 颜嘉钦 on 9/14/21.
//
#include <iostream>
#include "../header/compressor.h"
#include "../char_buffer.h"

#define flow_compressor
#ifdef flow_compressor

using namespace std;

char replace_space = '^';
char replace_endl = '%';

OLC check_length(char_buffer buffer,ifstream *in);

/**
 * 将源文件指定长度字符压缩，并输出到文件。
 * 该方法一次性读取所有字符再开始压缩。
 * @param begin 字符串首
 * @param end 字符串尾
 * @param buffer_length 缓冲区长度
 */
void compress(ifstream *in, ofstream *out, int buffer_length, int cross_length){

    char_buffer buffer = char_buffer(buffer_length+cross_length);

    do{
        buffer.add(in->get());
    }while(buffer.getTail(buffer_length)!=buffer.cursor && !in->eof());
    //先让Tail读取到留出缓冲区的空间，初始化。
    for(char* p = buffer.cursor;p!=buffer.getCursor(-1);p++){
        cout<<*p<<" ";
    }
    cout<<endl;

    int olc_length = 0;
    int olc_offset = 0;
    char *olc_next;
    while(*buffer.getCursor(1)!='\0'){

        olc_offset = 0;
        olc_length = 0;
        //OLC olc = check_length(buffer,in);

        {
            int offset = 0;
            olc_next = buffer.getCursor(0);
            for(char *begin = buffer.getTail(0);begin!=buffer.getCursor(0);begin = buffer.next(begin)){
                char *i = begin;
                char *j = buffer.getCursor(0);
                int count = 0;
                bool top = false;
                //如果冲破了tail，则会覆盖尾部数据，就不可以也无需再检查之后的匹配长度
                while(*i==*j){
                    i = buffer.next(i);
                    j = buffer.next(j);
                    if(j==buffer.getTail(0)){
                        top = true;
                        buffer.add(in->eof() ? '\0' : in->get());
                        buffer.moveCursor(1);
                    }
                    count++;
                }
                if(top){
                    olc_length = count;
                    olc_offset = offset;
                    olc_next = j;
                    break;
                }
                if(count>olc_length){
                    olc_length = count;
                    olc_offset = offset;
                    olc_next = j;
                }
                offset++;
            }
        }

        buffer.cursor = olc_next;
        char t = *buffer.cursor;

        buffer.moveCursor(1);
        if(t=='\n'){
            t=replace_endl;
        }else if(t==' '){
            t=replace_space;
        }
        *out<<(char)(olc_offset+64)<<(char)(olc_length+64)<<t<<endl;
        cout<<olc_offset<<" "<<olc_length<<" "<<t<<endl;
        while(buffer.getTail(buffer_length)!=buffer.cursor){
            buffer.add(in->eof() ? '\0' : in->get());
        }

    }
    in->close();
    out->close();
}


/**
 * 寻找最大匹配字符串，并返回olc。
 * @param L_begin 字典缓冲区header
 * @param R_begin 先行缓冲区header
 * @return olc
 */
OLC check_length(char_buffer buffer,ifstream *in){
    OLC olc;
    int offset = 0;
    olc.next = buffer.getCursor(0);
    for(char *begin = buffer.getTail(0);begin!=buffer.getCursor(0);begin = buffer.next(begin)){
        char *i = begin;
        char *j = buffer.getCursor(0);
        int count = 0;
        bool top = false;
        //如果冲破了tail，则会覆盖尾部数据，就不可以也无需再检查之后的匹配长度
        while(*i==*j){
            i = buffer.next(i);
            j = buffer.next(j);
            if(j==buffer.getTail(0)){
                top = true;
                buffer.add(in->eof() ? '\0' : in->get());
                buffer.moveCursor(1);
            }
            count++;
        }
        if(top){
            olc.length = count;
            olc.offset = offset;
            olc.next = j;
            return olc;
        }
        if(count>olc.length){
            olc.length = count;
            olc.offset = offset;
            olc.next = j;
        }
        offset++;
    }
    return olc;
}

/**
 * 输入字符，解压到另一个文件。
 * @param buffer_length
 */
void decompress(ifstream *in,ofstream *out,int buffer_length) {

    char_buffer buffer = char_buffer(buffer_length+1);
    //在这里创建实例，并且打印了第一次数据

    buffer.tail = buffer.getCursor(1);

    char olc[3];
    while (*in>>olc) {
        int offset = olc[0]-64;
        int length = olc[1]-64;
        char ch = olc[2];
        buffer.print();
        //在这里打印了第二次数据

        if (length == 0) {
            if(ch==replace_endl){
                *out<<buffer.push('\n');
            }else if(ch==replace_space) {
                *out << buffer.push(' ');
            }else{
                *out<<buffer.push(ch);
            }
            continue;
        }
        //无匹配字符直接打印

        char* beg = buffer.getTail(offset);
        buffer.print();

        for (int a = 0; a < length; a++) {
            *out<<buffer.push(*beg);
            buffer.next(beg);
        }

        if (ch != '\0') {
            if(ch==replace_endl){
                *out<<buffer.push('\n');
            }else if(ch==replace_space) {
                *out << buffer.push(' ');
            }else{
                *out<<buffer.push(ch);
            }
        } else {
            break;
        }
        //打印匹配字符串与下一个字符
    }
    in->close();
    out->close();
}

#endif //flow_compressor