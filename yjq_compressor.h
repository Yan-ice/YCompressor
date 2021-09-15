//
// Created by 颜嘉钦 on 9/14/21.
//

#ifndef YCOMPRESS_YJQ_COMPRESSOR_H
#define YCOMPRESS_YJQ_COMPRESSOR_H


struct OLC{
    int offset = 0;
    int length = 0;
    char *next;
};

void compress(char sourceFileName[],char targetFileName[],int buffer_length, int package_length);
OLC check_length(char *L_begin, char *R_begin);

void decompress(char sourceFileName[],char targetFileName[],int buffer_length);

#endif //YCOMPRESS_YJQ_COMPRESSOR_H
