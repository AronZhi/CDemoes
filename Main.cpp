#include "PyObj.h"

int main()
{
    PyObj pyobj;
    if (!pyobj.Create("/home/zyw/Documents/Demo/script", "HelloPython"))
        return -1;
    
    pyobj.Run("Hello");
    pyobj.Delete();
    return 0;
}