#ifndef PY_OBJ
#define PY_OBJ

#include <string>
#include <python3.6/Python.h>

class PyObj
{
public:
    PyObj();
    virtual ~PyObj();

    virtual int8_t Create() = 0;
    virtual void Delete() = 0;

    int8_t Excute(const std::string& funcName, PyObject* args);

protected:
    int8_t _CreateModule(const std::string& path, const std::string& fileName);
    void _DeleteModule();

private:
    PyObject* _obj;
};

#endif // PY_OBJ