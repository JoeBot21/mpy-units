#include <python3.13/Python.h>

import test_cpp_module;

static PyObject * hello_world(PyObject *self, PyObject *args) {
  return Py_BuildValue("s", test_cpp_module::hello_world_cpp().c_str());
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
