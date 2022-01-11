#include <Python.h>
#include "libshared.h"
#include "wrapper.h"

PyObject * add(PyObject * self, PyObject * args) {
	int num1, num2, sum;
	
	if(!PyArg_ParseTuple(args, "ii", &num1, &num2))
		return NULL;
	
	sum = add(num1, num2);
	
	return Py_BuildValue("i", sum);
}

