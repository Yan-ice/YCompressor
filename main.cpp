
#include "yjq_compressor.h"
using namespace std;


int main() {
    compress("..//testfile//sourcefile.txt","..//testfile//targetfile.txt",5,2000);
    decompress("..//testfile//targetfile.txt","..//testfile//compare.txt",5);
    return 0;
}

