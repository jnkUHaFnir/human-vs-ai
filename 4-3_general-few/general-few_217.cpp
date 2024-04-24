void deallocateByteBuffer(ByteBuffer* buffer) {
    delete[] buffer->dataBuf;
    buffer->dataBuf = nullptr;
}
%typemap(freearg) uint8_t * (%typemap(freearg) uint8_t *temp) {
    // Call the wrapper function to deallocate the memory
    deallocateByteBuffer((ByteBuffer*)$input);
}
%typemap(in) uint8_t * (uint8_t *temp) {
    // Existing code for memory allocation
    $1 = temp;

    // Add this line to set the dataBuf pointer to NULL
    ((ByteBuffer*)$input)->dataBuf = nullptr;
}
