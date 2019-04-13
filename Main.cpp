#include <iostream>
#include "PyObj.h"

int main()
{
    PyObj pyobj;
    int8_t ret = pyobj.Create("/home/zyw/Documents/Demo/script", "HelloPython");
    if (ret < 0)
    {
        std::cout << "create: " << ret << std::endl;
    }
        
    ret = pyobj.Run("Hello");
    if (ret < 0)
    {
        std::cout << "run: " << ret << std::endl;
    }

    pyobj.Delete();
    return 0;
}