import std;

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include "test_module.hpp"


static PyObject * hello_world(PyObject *self, PyObject *args) {
  return Py_BuildValue("s", cpp_module::hello_world_cpp().c_str());
}

static PyMethodDef module_functions[] = {
    {"hello_world", hello_world, METH_VARARGS, "Say hello."},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef test_module = {
    .m_methods = module_functions,
};

PyMODINIT_FUNC PyInit_test_module(void) {
    return PyModuleDef_Init(&test_module);
}
