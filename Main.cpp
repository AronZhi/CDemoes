#include <iostream>
#include "HelloPython.h"

int main()
{
    HelloPython pyobj("/home/zyw/Documents/Demo/script", "HelloPython");
    PyErr ret = pyobj.Create();
    if (ret != PY_SUCCESS)
    {
        std::cout << "create: " << ret << std::endl;
    }
        
    pyobj.Hello(ret);
    if (ret != PY_SUCCESS)
    {
        std::cout << "Hello Fail: " << ret << std::endl;
    }

    int number = pyobj.Fib(6, ret);
    if (ret != PY_SUCCESS)
    {
        std::cout << "Fib Fail: " << ret << std::endl;
    }
    else
    {
        std::cout << "Fib number: " << number << std::endl;
    }
    
    pyobj.Delete();
    return 0;
}