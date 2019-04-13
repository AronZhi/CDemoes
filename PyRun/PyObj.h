#ifndef PY_OBJ
#define PY_OBJ

#include <string>
#include <python3.6/Python.h>

class PyObj
{
public:
    PyObj();
    virtual ~PyObj();

    int8_t Create(const std::string& path, const std::string& fileName);
    void Delete();

    void Run(const std::string& funcName);
    
private:
    PyObject* _obj;
};

#endif // PY_OBJ