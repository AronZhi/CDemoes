#ifndef PY_OBJ
#define PY_OBJ

#include <string>
#include <python3.6/Python.h>

enum PyErr
{
        PY_SUCCESS = 0,
        PY_FAIL = 1,
        PY_NO_OBJ = 2,
        PY_INITIAL_FAIL = 3,
        PY_MODULE_ERR = 4,
        PY_NO_DIC = 5,
        PY_FUNC_ERR = 6
};

class PyObj
{
public:
    PyObj();
    virtual ~PyObj();

    virtual PyErr Create() = 0;
    virtual void Delete() = 0;

    PyErr Excute(const std::string& funcName, PyObject* args, PyObject*& ret);

protected:
    PyErr _CreateModule(const std::string& path, const std::string& fileName);
    void _DeleteModule();

private:
    PyObject* _obj;
};

#endif // PY_OBJ