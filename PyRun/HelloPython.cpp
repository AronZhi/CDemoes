#include "HelloPython.h"

HelloPython::HelloPython()
:_modulePath(""), _moduleName("")
{

}

HelloPython::HelloPython(const std::string& modulePath, const std::string& moduleName)
:_modulePath(modulePath), _moduleName(moduleName)
{

}

HelloPython::~HelloPython()
{

}

int8_t HelloPython::Create()
{
    return _CreateModule(_modulePath, _moduleName);
}

void HelloPython::Delete()
{
    _DeleteModule();
}

int8_t HelloPython::Hello()
{
    return Excute("Hello", NULL);
}