#include "PyObj.h"
#include <boost/format.hpp>

PyObj::PyObj()
:_obj(NULL)
{

}

PyObj::~PyObj()
{

}

PyErr PyObj::_CreateModule(const std::string& path, const std::string& fileName)
{
    Py_Initialize();
    if (!Py_IsInitialized())
    {
        return PY_INITIAL_FAIL;
    }
        
    
    PyRun_SimpleString("import sys");

    std::string filePath = (boost::format("sys.path.append('%s')") % path.c_str()).str();
    PyRun_SimpleString(filePath.c_str());

    _obj = PyImport_ImportModule(fileName.c_str());
    if (!_obj)
    {
        return PY_MODULE_ERR;
    }

    return PY_SUCCESS;
}

void PyObj::_DeleteModule()
{
    Py_Finalize();
}

PyErr PyObj::Excute(const std::string& funcName, PyObject* args, PyObject*& ret)
{
    if (!_obj)
    {
        return PY_NO_OBJ;
    }
        
    PyObject* pDict = PyModule_GetDict(_obj);
    if (!pDict)
    {
        return PY_NO_DIC;
    }
    
    PyObject* pFunc = PyDict_GetItemString(pDict, funcName.c_str());
    if (!pFunc || !PyCallable_Check(pFunc))
    {
        return PY_FUNC_ERR;
    }
    
    ret = PyObject_CallObject(pFunc, args);
    
    return PY_SUCCESS;
}