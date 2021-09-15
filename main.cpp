
#include "header/compressor.h"
using namespace std;

ifstream in1 = ifstream();
//从文件读取信息

ofstream out1 = ofstream();
//向文件写入信息

ifstream in2 = ifstream();
//从文件读取信息

ofstream out2 = ofstream();
//向文件写入信息

int main() {

//    in1.open("..//testfile//DataFrameM256R40.txt",ios::out | ios::in);
//    out1.open("..//testfile//target.txt",ios::out | ios::in);
//    compress(&in1,&out1,5,75);

    in2.open("..//testfile//target.txt",ios::out | ios::in);
    out2.open("..//testfile//compare.txt",ios::out | ios::in);
    decompress(&in2,&out2,5);
    return 0;
}

