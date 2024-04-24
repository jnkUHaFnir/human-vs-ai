struct ByteBuffer
{
    int length;
    uint8_t * dataBuf;       
};

void clear_buffer_data(ByteBuffer* buf)
{
    if(buf->dataBuf != NULL){
        delete [] buf->dataBuf;
        buf->dataBuf = NULL;
        buf->length = 0;
    }
}

Python Usage code:
```python
import mymodule

for i in range(10000):
    byteBuffer = mymodule.ByteBuffer()
    byteBuffer.length = 10000
    byteBuffer.dataBuf = [0]*10000
    # ... use byteBuffer
    mymodule.clear_buffer_data(byteBuffer)
    del byteBuffer
