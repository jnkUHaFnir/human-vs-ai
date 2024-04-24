%typemap(freearg) uint8_t *, int {
    delete[] $1;
}
%inline %{
static void ByteBuffer_dealloc(ByteBuffer* self) {
    if (self->dataBuf) {
        delete[] self->dataBuf;
    }
    Py_TYPE(self)->tp_free((PyObject*)self);
}
%}
%typemap(out) uint8_t*, int {
    $result = SWIG_NewPointerObj($1, $2, $*1_descriptor, 0);
}

%inline %{
%{
    struct ByteBuffer
    {
        int length;
        uint8_t* dataBuf;
    };
%}

void fillBuffer(ByteBuffer* buff) {
    buff->dataBuf = new uint8_t[buff->length];
    for (int i = 0; i < buff->length; i++) {
        buff->dataBuf[i] = i; // Initialize with some meaningful data
    }
}

ByteBuffer* createByteBuffer(int length) {
    ByteBuffer* buff = new ByteBuffer;
    buff->length = length;
    buff->dataBuf = NULL;
    return buff;
}
%}
