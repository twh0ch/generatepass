#include "sumpr1.h"

int main(int argc, char* argv[])
{

    setlocale(LC_ALL, "rus");

    //instruction();

    checkArguments(argc,argv);

    countFlags(argc, argv);

    checkFlags(argc, argv);

    checkSymbolFlags(argc, argv);

    checkSizeFlags(argc, argv);
    
    genPass(argc, argv);

    return 0;

}