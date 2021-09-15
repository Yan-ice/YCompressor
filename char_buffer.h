//
// Created by 颜嘉钦 on 9/14/21.
//

#ifndef YCOMPRESS_CHAR_BUFFER_H
#define YCOMPRESS_CHAR_BUFFER_H

class char_buffer {
private:
    char* begin;
    //数组的左端
    char* end;
    //数组的右端
    char* cursor;
    //数组尾部(添加元素)
    char* tail;
    //数组尾部(添加元素)
public:
    /**
     * 建立一个环形数组作为缓冲区。
     * @param size 环的大小
     */
    explicit char_buffer(int size);

    ~char_buffer();

    /**
     * 将新的元素插入光标，然后将头光标向后移一位。
     * （附加内容：打印插入的元素）
     * @param ch 元素
     */
    char push(char ch);

    /**
     * 以头光标位置为基准，获得指定下标的元素。
     * 如果下标为正，则为光标后移，负则前移。
     * 如果下标为0，则返回光标本身。
     * @param num 与光标的相对位置
     * @return 指定位置的字符指针
     */
    char* getCursor(int num);
    /**
     * 以尾光标位置为基准，获得指定下标的元素。
     * 如果下标为正，则为光标后移，负则前移。
     * 如果下标为0，则返回光标本身。
     * @param num 与光标的相对位置
     * @return 指定位置的字符指针
     */
    char* getTail(int num);

    char* next(char* p);
    char* last(char* p);
};


#endif //YCOMPRESS_CHAR_BUFFER_H
