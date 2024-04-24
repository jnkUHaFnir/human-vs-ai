%module(directors="1") mymodule

%typemap(in) uint8_t * (uint8_t *temp){
    int length = PySequence_Length($input);
    temp = new uint8_t[length];    // memory allocated here
    for(int i=0; i<length; i++) {
        PyObject *o = PySequence_GetItem($input,i);
        if (PyNumber_Check(o)) {
            temp[i] = (uint8_t) PyLong_AsLong(o);
        } else {
            PyErr_SetString(PyExc_ValueError,"Sequence elements must be uint8_t");      
            return NULL;
        }
    }
    $1 = temp;
}

%typemap(freearg) uint8_t * {
    delete[] $1;  // Free the memory allocated for dataBuf
}

struct ByteBuffer
{
    int length;
    uint8_t * dataBuf;       
};
