#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "wrapper.h"
#include <numpy/arrayobject.h>


char sumfunc_docs[] = "Adds to 32-bit integers.";

PyMethodDef mylib_funcs[] = {
	{
		"sum",
		(PyCFunction)sum,
		METH_VARARGS,
		sumfunc_docs
	},
	{NULL}
};

char mylib_docs[] = "This is hello world module.";

PyModuleDef mylib_mod = {
	PyModuleDef_HEAD_INIT,
	"mylib",
	mylib_docs,
	-1,
	mylib_funcs,
};

PyMODINIT_FUNC PyInit_mylib(void) {
	import_array();
	return PyModule_Create(&mylib_mod);
}
