#include <iostream>
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include "display_array.h"

namespace py = pybind11;

/* C++ function that redirects to C func */
void display(py::array_t<unsigned char> input1){

	/*  read input arrays buffer_info */
	auto buf1 = input1.request();

	/*  variables */
	unsigned char *ptr1 = (unsigned char *) buf1.ptr;
	size_t b = buf1.shape[0];
	size_t r = buf1.shape[1];
	size_t c = buf1.shape[2];
	size_t k = buf1.shape[3];

	size_t s1 = buf1.strides[0];
	size_t s2 = buf1.strides[1];
	size_t s3 = buf1.strides[2];
	size_t s4 = buf1.strides[3];

	std::cout << "Shape: " << b << ","  << r << "," << c << "," << k << std::endl;
	std::cout << "Strides: " << s1 << ","  << s2 << "," << s3 << "," << s4 << std::endl;

	// C code call 
	loop_array(ptr1, (int)b, (int)r, (int)c, (int)k, (int)s1, (int)s2, (int)s3, (int)s4);
}


/* Wrapping routines with PyBind */
PYBIND11_MODULE(wrapper, m) {
	    m.doc() = ""; // optional module docstring
	    m.def("display", &display, "display array");
}

