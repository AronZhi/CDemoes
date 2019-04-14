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

int8_t HelloPython::Run(const std::string& funcName)
{
    if (!_obj)
    {
        return -1;
    }
        
    PyObject* pDict = PyModule_GetDict(_obj);
    if (!pDict)
    {
        return -2;
    }
    
    PyObject* pFunc = PyDict_GetItemString(pDict, funcName.c_str());
    if (!pFunc || !PyCallable_Check(pFunc))
    {
        return -3;
    }
    
    PyObject_CallObject(pFunc, NULL);
    return 0;
}