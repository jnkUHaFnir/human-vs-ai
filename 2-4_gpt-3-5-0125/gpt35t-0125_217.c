
With this update, the custom deallocator function `freearg` will free the memory allocated for the dataBuf when the Python object is deleted. This should help prevent the memory leak you were experiencing.

Make sure to include "cpointer.i" in your SWIG interface file to access the calloc function. Additionally, you may need to adjust the memory allocation and deallocation functions based on your specific needs and memory management strategies.
