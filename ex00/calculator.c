
#include <Python.h>

int Cdiv(int a, int b)
{
  return a / b;
}

static PyObject* _div(PyObject* self, PyObject* args)
{
    int a, b;
 
    if (PyTuple_Size(args) != 2) {
        PyErr_SetString(self, "divd args error");
    }

    if (!PyArg_ParseTuple(args, "ii", &a, &b))
        return NULL;

    if (b == 0) {
        PyErr_SetString(PyExc_ZeroDivisionError, "Cannot divide a zero");
        Py_INCREF(Py_None);
        return Py_None;
    }
 
    return Py_BuildValue("i", Cdiv(a, b));
}

int Cmul(int a, int b)
{
  return a * b;
}

static PyObject* _mul(PyObject* self, PyObject* args)
{
    int a, b;
 
    if (PyTuple_Size(args) != 2) {
        PyErr_SetString(self, "mul args error");
    }

    if (!PyArg_ParseTuple(args, "ii", &a, &b))
        return NULL;
 
    return Py_BuildValue("i", Cmul(a, b));
}

int Csub(int a, int b)
{
  return a - b;
}

static PyObject* _sub(PyObject* self, PyObject* args)
{
    int a, b;
 
    if (PyTuple_Size(args) != 2) {
        PyErr_SetString(self, "sub args error");
    }

    if (!PyArg_ParseTuple(args, "ii", &a, &b))
        return NULL;
 
    return Py_BuildValue("i", Csub(a, b));
}

int Cadd(int a, int b)
{
  return a + b;
}
 
static PyObject* _add(PyObject* self, PyObject* args)
{
    int a, b;
 
    if (PyTuple_Size(args) != 2) {
        PyErr_SetString(self, "add args error");
    }

    if (!PyArg_ParseTuple(args, "ii", &a, &b))
        return NULL;
 
    return Py_BuildValue("i", Cadd(a, b));
}

static PyObject* version(PyObject* self)
{
    return Py_BuildValue("s", "Version 1.0");
}
 
static PyMethodDef calculators[] = {
    {"div", _div, METH_VARARGS, "Calculate division of values."},
    {"mul", _mul, METH_VARARGS, "Calculate product of values."},
    {"sub", _sub, METH_VARARGS, "Calculate value difference."},
    {"add", _add, METH_VARARGS, "Calculate sum of values."},
    {"version", (PyCFunction)version, METH_NOARGS, "Returns the version."},
    {NULL, NULL, 0, NULL}
};
 
static struct PyModuleDef calculator = {
	PyModuleDef_HEAD_INIT,
	"calculator",
	"Calculate Module",
	-1,
	calculators
};

PyMODINIT_FUNC PyInit_calculator(void)
{
    return PyModule_Create(&calculator);
}
