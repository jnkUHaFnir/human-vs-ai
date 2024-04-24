%module(directors="1") mymodule

%typemap(in) uint8_t * (uint8_t *temp){
    int length = PySequence_Length($input);
    temp = new uint8_t[length];
    for(int i=0; i<length; i++) {
        PyObject *o = PySequence_GetItem($input,i);
        if (PyNumber_Check(o)) {
            temp[i] = (uint8_t) PyLong_AsLong(o);
        } else {
            PyErr_SetString(PyExc_ValueError,"Sequence elements must be uint8_t");      
            delete[] temp;  // Free the allocated memory before returning NULL
            return NULL;
        }
        Py_DECREF(o);  // Decrement the reference count as we're done using the object
    }

    $1 = temp;
    $1_descriptor->dealloc = [](void *ptr) {
        if(ptr) {
            delete[] static_cast<uint8_t*>(ptr);  // Free the allocated memory when the object is deleted
        }
    };
}
