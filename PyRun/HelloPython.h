#ifndef HELLO_PYTHON
#define HELLO_PYTHON

#include <string>
#include "PyObj.h"

class HelloPython : public PyObj
{
public:
    HelloPython();
    HelloPython(const std::string& modulePath, const std::string& moduleName);
    ~HelloPython();
    
    int8_t Create();
    void Delete();

    int8_t Run(const std::string& funcName);

private:
    std::string _modulePath;
    std::string _moduleName;
};

#endif // HELLO_PYTHON