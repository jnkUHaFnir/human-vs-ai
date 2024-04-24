struct ByteBuffer
{
    int length;
    uint8_t * dataBuf;

    ~ByteBuffer() {
        delete [] dataBuf;
    }
};
byteBuffer = mymodule.ByteBuffer()
byteBuffer.length = 10000
byteBuffer.dataBuf = [0]*10000
# ... use byteBuffer
byteBuffer.deleteDataBuf()  # Call the custom dealloc method
del byteBuffer
