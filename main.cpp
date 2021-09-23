
#include "header/compressor.h"
using namespace std;


int main() {

    ifstream in1 = ifstream();
//从文件读取信息
    ofstream out1 = ofstream();
//向文件写入信息

    in1.open("..//testfile//sourceFile.txt",ios::out | ios::in);
    out1.open("..//testfile//compressedFile.txt",ios::out | ios::in);
    compress(in1,out1,72,72);
    in1.close();
    out1.close();

    in1.open("..//testfile//compressedFile.txt",ios::out | ios::in);
    out1.open("..//testfile//uncompressedFile.txt",ios::out | ios::in);
    decompress(in1,out1,72);
    in1.close();
    out1.close();

//    in1.open("..//testfile//compressedFile.txt",ios::out | ios::in);
//    out1.open("..//testfile//compressedFile2.txt",ios::out | ios::in);
//    compress(in1,out1,75,75);
//    in1.close();
//    out1.close();
//
//    in1.open("..//testfile//compressedFile2.txt",ios::out | ios::in);
//    out1.open("..//testfile//uncompressedFile.txt",ios::out | ios::in);
//    decompress(in1,out1,75);
//
//    in1.close();
//    out1.close();
//    in1.open("..//testfile//uncompressedFile.txt",ios::out | ios::in);
//    out1.open("..//testfile//uncompressedFile2.txt",ios::out | ios::in);
//    decompress(in1,out1,75);
//    in1.close();
//    out1.close();

    return 0;
}

