#include "PyObj.h"
#include <boost/format.hpp>

PyObj::PyObj()
:_obj(NULL)
{

}

PyObj::~PyObj()
{

}

int8_t PyObj::Create(const std::string& path, const std::string& fileName)
{
    Py_Initialize();
    if (!Py_IsInitialized())
    {
        return -1;
    }
        
    
    PyRun_SimpleString("import sys");

    std::string filePath = (boost::format("sys.path.append('%s')") % path.c_str()).str();
    PyRun_SimpleString(filePath.c_str());

    _obj = PyImport_ImportModule(fileName.c_str());
    if (!_obj)
    {
        return -2;
    }
}

void PyObj::Delete()
{
    Py_Finalize();
}

void PyObj::Run(const std::string& funcName)
{
    if (!_obj)
        return;
        
    PyObject* pDict = PyModule_GetDict(_obj);
    if (!pDict)
        return;
    
    PyObject* pFunc = PyDict_GetItemString(pDict, funcName.c_str());
    if (!pFunc || !PyCallable_Check(pFunc))
        return;
    
    PyObject_CallObject(pFunc, NULL);
}