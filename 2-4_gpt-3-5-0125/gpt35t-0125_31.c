#include <openssl/bio.h>
#include <openssl/evp.h>

char* binaryToBase64(unsigned char* binaryData, int dataSize) {
    BIO *bmem, *b64;
    BUF_MEM *bptr;

    b64 = BIO_new(BIO_f_base64());
    bmem = BIO_new(BIO_s_mem());
    b64 = BIO_push(b64, bmem);
    
    BIO_write(b64, binaryData, dataSize);
    BIO_flush(b64);
    
    BIO_get_mem_ptr(b64, &bptr);
    
    char *base64Data = (char*)malloc(bptr->length);
    memcpy(base64Data, bptr->data, bptr->length-1);
    base64Data[bptr->length-1] = '\0';
    
    BIO_free_all(b64);
    
    return base64Data;
}
