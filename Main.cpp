#include <iostream>
#include "HelloPython.h"

int main()
{
    HelloPython pyobj("/home/zyw/Documents/Demo/script", "HelloPython");
    int8_t ret = pyobj.Create();
    if (ret < 0)
    {
        std::cout << "create: " << ret << std::endl;
    }
        
    ret = pyobj.Hello();
    if (ret < 0)
    {
        std::cout << "run: " << ret << std::endl;
    }

    pyobj.Delete();
    return 0;
}