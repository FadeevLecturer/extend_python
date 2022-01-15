#include "libhelloworld.h"


// function docstring
char hellofunc_docs[] = "Says hello";
char byefunc_docs[] = "Says bye to the name specified";
char callfunc_docs[] = "Call funtion with one argument";


PyMethodDef helloworld_funcs[] = {
	{	
		"say_hello", // name of function in python
		(PyCFunction)hello, // C function to be exported 
		METH_NOARGS, // NOARGS --- no arguments
		hellofunc_docs // docstring
	},
	{
		"say_bye", 
		(PyCFunction)bye, // C function to be exported 
		METH_VARARGS, // VARARGS --- positional arguments
		byefunc_docs // docstring
	},
	{
		"call",
		(PyCFunction)call,
		METH_VARARGS,
		callfunc_docs
	},
	{NULL}
};

// module docstring
char helloworldmod_docs[] = "This is hello world module."; 


// module table
PyModuleDef helloworld_mod = {
	PyModuleDef_HEAD_INIT, // special symbol
	"helloworld", // name of module in python
	helloworldmod_docs, // docstring
	-1, 
	helloworld_funcs // functions to export
};

PyMODINIT_FUNC PyInit_helloworld(void) {
	return PyModule_Create(&helloworld_mod);
}
