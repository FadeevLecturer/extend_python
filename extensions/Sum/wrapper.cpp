#define PY_SSIZE_T_CLEAN
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <numpy/arrayobject.h>
#include <numeric>
#include "libshared.h"
#include "wrapper.h"


PyObject* sum(PyObject* self, PyObject* args) {

	PyObject* ndarray_obj = NULL;
	
	if(!PyArg_ParseTuple(args, "O", &ndarray_obj))
		return NULL;
	
	PyArrayObject* ndarray = reinterpret_cast<PyArrayObject*>(ndarray_obj);
	/*
	if (PyArray_DTYPE(ndarray)->type_num != PyArray_DOUBLE) {
		PyErr_SetString(PyExc_ValueError, "array must be of type float");
		return NULL;
	}
	*/
	int ndim = PyArray_NDIM(ndarray);	
	npy_intp *shape = PyArray_SHAPE(ndarray);	
	
	npy_intp nelem = 1;
	for(int i=0; i < ndim; ++i){
		nelem *= shape[i];
	}
	/*
	std::size_t nelem = std::accumulate(shape, 
								shape + ndim, 
								1, 
								std::multiplies<npy_intp>());
	*/
	double *array = reinterpret_cast<double*>(PyArray_DATA(ndarray));
	double s = sum(array, nelem);
	
	return PyFloat_FromDouble(s);
}

