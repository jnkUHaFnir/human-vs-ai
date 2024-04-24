%module(directors="1") mymodule

%typemap(in) uint8_t * (uint8_t *temp) {
    // ... same as before ...        
}

%extend ByteBuffer {
    // Destructor
    ~ByteBuffer() {
        delete[] dataBuf;
    }
}

%pythoncode %{
def __ByteBuffer__dealloc__(self):
    self.thisptr.__swig_destroy__(self)

mymodule.ByteBuffer.__dealloc__ = __ByteBuffer__dealloc__
%}
