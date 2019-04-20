#include <iostream>
#include <string>
#include "ExcutePyRun.h"

int main(int argc, char** argv)
{
    if (argc != 2)
        return -1;
    
    std::string target(argv[1]);
    if (target == "python")
        ExcutePyRun();
    return 0;
}