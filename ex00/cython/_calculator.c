#define PY_SSIZE_T_CLEAN
// #include <Python.h>
#include <D:/Python3/include/Python.h>


static PyObject *LosetupError;


static PyObject* _calculator(PyObject* self){
    return PyUnicode_FromString("It will be a calculator!");
}


static struct PyMethodDef methods[] = {
    {"_calculator", (PyCFunction)_calculator, METH_NOARGS},
    {NULL, NULL}
};


static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "_calulator",
    NULL,
    -1,
    methods
};

PyMODINIT_FUNC PyInit__calculator(void) {
    return PyModule_Create(&module);
}