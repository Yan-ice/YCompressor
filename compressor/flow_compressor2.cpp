//
// Created by 颜嘉钦 on 9/14/21.
//

/**
 * 解压和压缩均用到了环形的链表。
 *
 * 压缩核心思路：
 * 1.建立一个长度为缓冲区长(设为H)+先行区长(设为L)的环形字符链表，链表上有两个光标cursor和tail。
 * 2.初始化时，链表中所有数据均为1,cursor和tail重合。
 * 3.tail重复从流读入一个字符并后移一位，直到tail光标到达cursor前H长度的位置。
 * 4.cursor后移到tail为先行区，tail后移到cursor的位置为缓冲区。按照最常规的LZ77算法匹配字符串，然后cursor前移到nextCharacter。
 *   如果匹配字符串时，匹配字符超出先行区(匹配字符串的指针碰到了tail），则tail立刻从流读入一个字符并后移一位，同时cursor后移一位。
 *   由于环形链表的缘故，tail的后移会覆盖缓冲区数据。所以，完成该次匹配将直接返回OLC，不再匹配下一个offset的字符串。
 *   (暂未实现) 如果一个字符没有匹配或匹配长度为1，则另起一行直接打印该字符，而不是OLC。
 * 5.重复3-4步，直到匹配完所有数据。
 *
 *
 * 解压核心思路：
 * 1.建立一个长度为缓冲区长+1的环形字符链表，链表上有两个光标cursor和tail。
 * 2.初始化时，tail在cursor后一位。
 * 3.一次读取一个OLC，如果长度为0则直接将nextChar赋值到cursor，
 *   如果长度不为0则从tail开始往后计算offset，找到对应位置后按照长度将字典赋值到cursor，最后赋值nextChar到cursor。
 *   每一次有字符赋值到cursor时，cursor和tail同时后移一位，并将赋值的字符扔给输出流。
 */

#include "../header/compressor.h"
#include "../header/char_buffer.h"

#define flow_compressor2
#ifdef flow_compressor2

using namespace std;

OLC check_length(char_buffer buffer,ifstream &in);

const static int read_offset = 4;
/**
 * 将源文件指定长度字符压缩，并输出到文件。
 * 该方法一次性读取所有字符再开始压缩。
 * @param begin 字符串首
 * @param end 字符串尾
 * @param buffer_length 缓冲区长度
 */
void compress(ifstream &in, ofstream &out, int buffer_length, int cross_length){

    char_buffer buffer = char_buffer(buffer_length+cross_length);
    bool direct_record_state = false;
    do{
        buffer.add(in.get()+read_offset);
    }while(buffer.getTail(buffer_length)!=buffer.cursor && !in.eof());
    //先让Tail读取到留出缓冲区的空间，初始化。

    int olc_length = 0;
    int olc_offset = 0;
    char *olc_next;
    while(*buffer.getCursor(1)!=0){
        //OLC olc = check_length(buffer,in);
        {
            olc_offset = 0;
            olc_length = 0;
            int offset = 0;
            olc_next = buffer.getCursor(0);
            for(char *begin = buffer.getTail(0);begin!=buffer.getCursor(0);buffer.next(begin)){
                char *i = begin;
                char *j = buffer.getCursor(0);

                int count = 0;
                bool top = false;
                //如果冲破了tail，则会覆盖尾部数据，就不可以也无需再检查之后的匹配长度
                while(*i==*j){
                    buffer.next(i);
                    buffer.next(j);
                    if(j==buffer.getTail(0)){
                        top = true;
                        buffer.add(in.eof() ? '\0' : in.get()+read_offset);
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
                if(count>1 && count>olc_length){
                    olc_length = count;
                    olc_offset = offset;
                    olc_next = j;
                }
                offset++;
            }
        }

        buffer.cursor = olc_next;
        if(olc_length>0){
            if(direct_record_state){
                direct_record_state = false;
                cout<<" - dir"<<endl;
                out<<(char)1;
            }
            cout<<olc_offset<<" "<<olc_length<<" "<<(int)*olc_next<<endl;
            out<<(char)(olc_offset+read_offset)<<(char)(olc_length+read_offset)<<*olc_next;
        }else{
            if(!direct_record_state){
                direct_record_state = true;
                out<<(char)1;
                cout<<"dir - ";
            }
            cout<<(*buffer.cursor);
            out<<*olc_next;
        }

        buffer.moveCursor(1);

        while(buffer.getTail(buffer_length)!=buffer.cursor){
            buffer.add(in.eof() ? '\0' : in.get()+read_offset);
        }

    }
    out<<'\0';
    in.close();
    out.close();
}


/**
 * 寻找最大匹配字符串，并返回olc。
 * @param L_begin 字典缓冲区header
 * @param R_begin 先行缓冲区header
 * @return olc
 */
OLC check_length(char_buffer buffer,ifstream &in){
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
                buffer.add(in.eof() ? '\0' : in.get());
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
        if(count>olc.length && count>1){
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
void decompress(ifstream &in,ofstream &out,int buffer_length) {
    char_buffer buffer = char_buffer(buffer_length+1);

    buffer.tail = buffer.getCursor(1);
    while (!in.eof()) {
        char flag = in.get();
        if(flag==0 || flag==-1){
            break;
        }
        if(flag==1){
            char c = in.get();
            while(c!=1 && c!=0){
                out<<buffer.push(c-read_offset);
                c = in.get();
            };
            if(c==0){
                break;
            }
            continue;
        }
        int offset = flag-read_offset;
        char length = in.get()-read_offset;
        char ch = in.get();

        //在这里打印了第二次数据

//        if (length == 0) {
//            out<<buffer.push(ch);
//            continue;
//        }
//        //无匹配字符直接打印

        char* beg = buffer.getTail(offset);

        for (int a = 0; a < length; a++) {
            if (*beg+read_offset!='\0') {
                out<<buffer.push(*beg);
                buffer.next(beg);
            } else {
                break;
            }
        }
        if(ch==read_offset || ch==read_offset-1){
            break;
        }
        out << buffer.push(ch-read_offset);
        //打印匹配字符串与下一个字符
    }
    in.close();
    out.close();
}

#endif //flow_compressor