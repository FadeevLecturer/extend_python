#include "wrapper.h"

char addfunc_docs[] = "Adds to 32-bit integers.";

PyMethodDef mylib_funcs[] = {
	{	
		"add",
		(PyCFunction)add,
		METH_VARARGS,
		addfunc_docs
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
	return PyModule_Create(&mylib_mod);
}
