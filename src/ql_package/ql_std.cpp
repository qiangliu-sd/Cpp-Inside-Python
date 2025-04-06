
#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <vector>
//#include <iostream>

// defined in this Cpp file:
// 	Py-module: 				ql_std_cpp
// 	Py-method (function): 	stdev_cpp
//	NOTE: PyInit_ql_std_cpp   (PyInit_module-name)

double standardDeviation_Cpp(const std::vector<double> & v)
{
	auto _1_over_N = 1.0 / v.size();
    double _sum = 0.0, _sum_sq =0.0;
 	for (auto & x : v) {
		//std::cout << "x = " << x << std::endl;
		_sum += x;
		_sum_sq += x*x;
	}
	double _mean = _sum *_1_over_N;

    return sqrt(_sum_sq *_1_over_N - _mean * _mean);
}

// wrap [standardDeviation_Cpp] inside
static PyObject * standardDeviation_Py(PyObject *self, PyObject* args)
{
    PyObject* _input;
    PyArg_ParseTuple(args, "O", &_input);

    Py_ssize_t _size = PyList_Size(_input); 
	PyObject* _item;
    std::vector<double> _vec(_size);
    for(Py_ssize_t k = 0; k < _size; ++k) {
		_item = PyList_GetItem(_input, k); 
        _vec[k] = PyLong_Check(_item)? PyLong_AsLong( _item ): 
			PyFloat_AS_DOUBLE( _item );
		//std::cout << "vec = " << _vec[k] << std::endl;
    }

	return PyFloat_FromDouble(standardDeviation_Cpp(_vec));
}

// define Py-Method [stdev_cpp] with [standardDeviation_Py] 
static PyMethodDef stdev_methods[] = {
	{"stdev_cpp", standardDeviation_Py,	METH_VARARGS,
	 "Py-method for computing Std-deviation from compiled C++"},
	{NULL, NULL, 0, NULL}		/* sentinel */
};

// define Py-Module contains [stdev_methods]
static struct PyModuleDef stdev_module = {
    PyModuleDef_HEAD_INIT,
    "ql_std_cpp",   /* module-name: same as Extension('ql_std_cpp', ...) in setup.py */
    "A Module based on compiled C++", /* module doc, can be NULL */
    -1,
    stdev_methods
};


// PyInit_module-name. binding with [stdev_module]
PyMODINIT_FUNC PyInit_ql_std_cpp(void)
{
    return PyModule_Create(&stdev_module);
}


int main(int argc, char *argv[])
{
    wchar_t * _ql_prog = Py_DecodeLocale(argv[0], NULL);
    if (_ql_prog == NULL) {
        fprintf(stderr, "ERR: Py_DecodeLocale argv[0] failed\n");
        exit(1);
    }

    // Add to built-in modules (not in any package)
    PyImport_AppendInittab("ql_std_cpp", PyInit_ql_std_cpp);

    // onto Python interpreter
    Py_SetProgramName(_ql_prog);
    Py_Initialize();
    PyMem_RawFree(_ql_prog);
	
    return 0;
}