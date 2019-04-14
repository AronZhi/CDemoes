#include "PyObj.h"
#include <boost/format.hpp>

PyObj::PyObj()
:_obj(NULL)
{

}

PyObj::~PyObj()
{

}

int8_t PyObj::_CreateModule(const std::string& path, const std::string& fileName)
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

    return 0;
}

void PyObj::_DeleteModule()
{
    Py_Finalize();
}
