#ifndef HELLO_PYTHON
#define HELLO_PYTHON

#include "PyObj.h"

class HelloPython : public PyObj
{
public:
    HelloPython();
    HelloPython(const std::string& modulePath, const std::string& moduleName);
    ~HelloPython();
    
    PyErr Create();
    void Delete();

    void Hello(PyErr& excuteResult);
    int Fib(int index, PyErr& excuteResult);

private:
    std::string _modulePath;
    std::string _moduleName;
};

#endif // HELLO_PYTHON