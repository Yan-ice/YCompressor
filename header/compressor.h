//
// Created by 颜嘉钦 on 9/14/21.
//
#include <iostream>
#include <fstream>

using namespace std;

struct OLC{
    int offset = 0;
    int length = 0;
    char *next;
};


void compress(ifstream *in, ofstream *out, int buffer_length, int package_length);

void decompress(ifstream *in,ofstream *out,int buffer_length);
