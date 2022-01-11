#include <Python.h>
#include <string>
#include <sstream>
#include "libhelloworld.h"

PyObject * hello(PyObject *self) {
	return PyUnicode_FromFormat("Hello from C++ extension!");
}

PyObject * bye(PyObject *self, PyObject *args) {
	const char *name;
	PyArg_ParseTuple(args, "s", &name); 
	
	std::string begining = "Bye, ";
	std::string ending = "!";
	std::string to_return = begining + std::string(name) + ending;
	
	return PyUnicode_FromFormat(to_return.c_str());
}
