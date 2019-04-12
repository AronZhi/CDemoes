#ifndef PY_OBJ
#define PY_OBJ

class PyObj
{
    public:
    PyObj();
    ~PyObj();

    bool Init();
    void Run();
    void Release();
}

#endif // PY_OBJ
