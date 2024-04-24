%typemap(freearg) uint8_t * (int length, uint8_t* temp) {
    // Retrieve the length passed from the Python code
    int length = $1;
    
    // Free the allocated memory for dataBuf
    delete[] temp;
}
%typemap(in) uint8_t * (int length, uint8_t *temp) {
    length = PySequence_Length($input);
    temp = new uint8_t[length];
    for(int i = 0; i < length; i++) {
        PyObject *o = PySequence_GetItem($input, i);
        if (PyNumber_Check(o)) {
            temp[i] = (uint8_t) PyLong_AsLong(o);
        } else {
            PyErr_SetString(PyExc_ValueError, "Sequence elements must be uint8_t");
            delete[] temp;  // Free the memory in case of an error
            return NULL;
        }
    }
    $1 = temp;
}
