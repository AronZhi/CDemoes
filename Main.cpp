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
        
    ret = pyobj.Hello();
    if (ret != PY_SUCCESS)
    {
        std::cout << "Hello Fail: " << ret << std::endl;
    }

    int number = 0;
    ret = pyobj.Fib(6, number);
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