struct ByteBuffer
{
    int length;
    uint8_t * dataBuf;

    ~ByteBuffer() {
        delete[] dataBuf;
    }
};
%typemap(in) uint8_t * (int length, uint8_t *temp){
    length = PySequence_Length($input);
    temp = new uint8_t[length];    // memory allocated here. How to free?
    for(int i=0; i<length; i++) {
        PyObject *o = PySequence_GetItem($input,i);
        if (PyNumber_Check(o)) {
            temp[i] = (uint8_t) PyLong_AsLong(o);
            //cout << (int)temp[i] << endl;
        } else {
            PyErr_SetString(PyExc_ValueError,"Sequence elements must be uint8_t");
            return NULL;
        }
    }
    $1 = temp;
}
%typemap(freearg) uint8_t * {
    delete[] $1;
}

This should prevent the memory leak and free the memory allocated by the typemap.
