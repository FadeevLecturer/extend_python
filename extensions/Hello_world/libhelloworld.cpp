#include <Python.h>
#include "libhelloworld.h"


// function with no arguments
PyObject * hello(PyObject *self) { // no arguments --- only self
	return PyUnicode_FromFormat("Hello from C++ extension!");
}

// function with one positional argument
PyObject * bye(PyObject *self, PyObject *args) { // args --- tuple of positional arguments 
	const char *name;
	
	// unpack tuple into string (s)
	if(!PyArg_ParseTuple(args, "s", &name))
		return NULL;
	
	return PyUnicode_FromFormat("Bye, %s!", name);
}

// funtion with two arguments
PyObject * call(PyObject * self, PyObject * args) {
	PyObject * Callable;
	PyObject * Argument;

	// unpack tuple into two python objects (OO)
	if(!PyArg_ParseTuple(args, "OO", &Callable, &Argument))
		return NULL;
	
	// check if the first arguments is callable
	if(!PyCallable_Check(Callable)){
		// raise the TypeError if it isn't
		PyErr_SetString(PyExc_TypeError, "First argument should be a callable");
		return NULL;
	}
	
	// pack the second argument in a tuple to pass it to Callable
	PyObject * Argumets_to_pass = PyTuple_Pack(1, Argument); 
	// Call the first argument (Callable) with the second argument (Argument)
	// NULL --- kwargs
	// PyObject_CallOneArg could be called in python 3.9 and later
	PyObject * To_Return = PyObject_Call(Callable, Argumets_to_pass, NULL); 
	
	return To_Return;
}

