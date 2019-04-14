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

PyErr HelloPython::Create()
{
    return _CreateModule(_modulePath, _moduleName);
}

void HelloPython::Delete()
{
    _DeleteModule();
}

void HelloPython::Hello(PyErr& excuteResult)
{
    PyObject* ret = NULL;
    excuteResult = Excute("Hello", NULL, ret);
}

int HelloPython::Fib(int index, PyErr& excuteResult)
{
    PyObject *pArg = Py_BuildValue("(i)", index);
    if (!pArg)
        return PY_FAIL;

    PyObject* ret = NULL;
    excuteResult = Excute("Fib", pArg, ret);
    int number = 0;
    if (excuteResult == PY_SUCCESS)
    {
        PyArg_Parse(ret, "i", &number);
    }
    return number;
}