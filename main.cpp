#include <iostream>
#include <fstream>
#include "char_buffer.h"
#include "yjq_compressor.h"
using namespace std;


int main() {
    signed       char    c1=   127   ;

    signed       char    c2=   1   ;

    int    csum = c1 + c2;

    cout    <<          csum   ;

    compress("//Users//yanjiaqin//CLionProjects//YCompress//sourcefile.txt","//Users//yanjiaqin//CLionProjects//YCompress//targetfile.txt",1000,2000);
    decompress("//Users//yanjiaqin//CLionProjects//YCompress//targetfile.txt","//Users//yanjiaqin//CLionProjects//YCompress//compare.txt",1000);
    return 0;
}

