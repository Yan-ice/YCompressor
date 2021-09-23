//
// Created by 颜嘉钦 on 9/22/20.
//

/**
 * 解压和压缩均用到了环形的链表。
 *
 * 压缩核心思路：
 * 1.设置缓冲区长度为X。此外，还有一个长度为X的模板区。
 * 2.读取X个数入缓冲区。比较模板区和缓冲区不同字符的数目。
 * 3.如果不到X/2个不同字符，打印标记A，然后依次打印每个不同字符替换值和位置，再加结束标记A。
 *   如果超过X/2个不同字符，直接打印缓冲区内容。
 * 4.将模板区更新为当前缓冲区，然后重复2-3步直到读取完所有内容。
 *
 *
 * 解压核心思路：
 * 1.读取标记。如果为A，则打印模板，并在遇到指定位置时打印替换字符。
 *   否则直接打印读到的所有内容。
 * 2.将模板区替换为最新打印的内容。
 * 3.重复步骤1-2，直到读取结束。
 */

#include "../header/compressor.h"
#include "../header/char_buffer.h"

#define delta_compressor
#ifdef delta_compressor

using namespace std;

/**
 * 标记 - 0为结束标记，1为差量/复制标记。
 */
const static int read_offset = 0;

/**
 * 将源文件指定长度字符压缩，并输出到文件。
 * 该方法一次性读取所有字符再开始压缩。
 * @param begin 字符串首
 * @param end 字符串尾
 * @param buffer_length 缓冲区长度
 */
void compress(ifstream &in, ofstream &out, int buffer_length, int adv){
    char_buffer buffer = char_buffer(buffer_length*2);
    do{
        out<<buffer.push(in.get()+read_offset);
    }while(buffer.getCursor(buffer_length)!=buffer.tail && !in.eof());
    //先让Tail读取第一批模板，初始化。

    string difference;
    int difCount = 0;
    while(!in.eof()){
        difCount = 0;
        difference = ((char)1);
        for(int a = 0;a<buffer_length;a++){

            char p = buffer.push(in.eof() ? '\0' : in.get()+read_offset);
            if(difCount*2<buffer_length){
                if(p!=*buffer.tail){
                    difCount+=1;
                    difference=difference+p+((char)(a+read_offset));
                }
            }
            buffer.next(buffer.tail);
        }
        //读取并比较缓冲区内容。

        if(difCount*2>=buffer_length || in.eof()){
            char* reader = buffer.tail;
            while(reader!=buffer.cursor){
                if(*reader=='\0' || *reader==-1 || *reader>65530){
                    out<<'\0';
                    return;
                }
                out<<*reader;
                buffer.next(reader);
            }
            //差异过多，则打印原内容。
        }else{
            out<<difference<<(char)1;
            //差异较少，则打印差异值。
        }
    }
    out<<'\0';

}


/**
 * 输入字符，解压到另一个文件。
 * @param buffer_length
 */
void decompress(ifstream &in,ofstream &out,int buffer_length) {
    char_buffer buffer = char_buffer(buffer_length*2);
    do{
        out<<buffer.push(in.get()-read_offset);
    }while(buffer.getCursor(buffer_length)!=buffer.tail && !in.eof());

    while(!in.eof()){
        char flag = in.get();
        if(flag <= 0){
            break;
        }
        if(flag == 1){
            //buffer.tail就是模板指针。
            int count = 0;
            //count是计算已经从模板打印了多少内容。
            char p = in.get();
            while(p!=1){
                p = p-read_offset;
                char locate = in.get()-read_offset;
                while(count<locate){
                    out<<buffer.push(*buffer.tail);
                    count++;
                    buffer.next(buffer.tail);
                }
                out<<buffer.push(p);
                count++;
                buffer.next(buffer.tail);
                p = in.get();
            }
            //结束后，继续从模板读取到尾。
            while(count!=buffer_length){
                out<<buffer.push(*buffer.tail);
                count++;
                buffer.next(buffer.tail);
            }

        }else{
            out<<buffer.push(flag-read_offset);
            buffer.next(buffer.tail);
            for(int a = 0;a<buffer_length-1;a++){
                char c = in.get();
                if(c==0){
                    return;
                }
                out<<buffer.push(c-read_offset);
                buffer.next(buffer.tail);
            }
        }
    }
}

#endif