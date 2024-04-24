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
            delete[] temp; // Free allocated memory
            return NULL;
        }
    }
    $1 = temp;
}

%typemap(freearg) uint8_t * {
    if ($1) {
        delete[] $1; // Free allocated memory
        $1 = NULL;
    }
}
