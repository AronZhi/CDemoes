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

PyErr HelloPython::Hello()
{
    PyObject* ret = NULL;
    return Excute("Hello", NULL, ret);
}

PyErr HelloPython::Fib(int index, int& number)
{
    PyObject *pArg = Py_BuildValue("(i)", index);
    if (!pArg)
        return PY_FAIL;

    PyObject* ret = NULL;
    PyErr execResult = Excute("Fib", pArg, ret);
    if (execResult == PY_SUCCESS)
    {
        PyArg_Parse(ret, "i", &number);
    }
    return execResult;
}