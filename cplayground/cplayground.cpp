#define PY_SSIZE_T_CLEAN
#include <Python.h>


/* tuple_setitem: a hack method to set item of tuple */
PyObject*
tuple_setitem(PyObject* self, PyObject* args)
{
	// parse args
	PyObject *tuple, *value;
	int idx;
	if (!PyArg_ParseTuple(args, "OiO", &tuple, &idx, &value))
	{
		Py_RETURN_FALSE;
	}
	
	// check tuple
	if (!PyTuple_Check(tuple))
	{
		PyErr_Format(
			PyExc_TypeError,
			"invalid tuple, %.200s",
			Py_TYPE(tuple)->tp_name
		);
		Py_RETURN_FALSE;
	}
	PyTupleObject* tp = (PyTupleObject*)tuple;

	// handle index below zero
	if (idx < 0)
	{
		idx += PyTuple_GET_SIZE(tp);
	}

	// check index range
	if ((size_t)idx >= (size_t)Py_SIZE(tp))
	{
		PyErr_SetString(
			PyExc_IndexError,
			"tuple index out of range"
		);
		Py_RETURN_FALSE;
	}

	// set value by index
	Py_INCREF(value);
	Py_SETREF(tp->ob_item[idx], value);
	Py_RETURN_TRUE;
}



static PyMethodDef cplayground_methods[] = {
	{
		"tuple_setitem",
		(PyCFunction)tuple_setitem,
		METH_VARARGS,
		"a hack method to set value in tuple"
	},
	{ nullptr, nullptr, 0, nullptr }
};

static PyModuleDef cplayground_module = {
	PyModuleDef_HEAD_INIT,
	"cplayground",  // module name
	"a c-python extension for testing",  // module desc
	0,
	cplayground_methods
};

PyMODINIT_FUNC
PyInit_cplayground()
{
	return PyModule_Create(&cplayground_module);
}
