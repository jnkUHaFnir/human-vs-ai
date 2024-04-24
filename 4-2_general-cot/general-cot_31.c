#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/buffer.h>

char* base64Encode(const unsigned char* input, int length) {
    BIO *bio, *b64;
    BUF_MEM *bufferPtr;
    
    b64 = BIO_new(BIO_f_base64());
    BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL);
    bio = BIO_new(BIO_s_mem());
    bio = BIO_push(b64, bio);
    
    BIO_write(bio, input, length);
    BIO_flush(bio);
    BIO_get_mem_ptr(bio, &bufferPtr);
    
    char* buff = (char*)malloc(bufferPtr->length + 1);
    memcpy(buff, bufferPtr->data, bufferPtr->length);
    buff[bufferPtr->length] = 0;
    
    BIO_free_all(bio);
    
    return buff;
}
int main() {
    unsigned char binaryData[] = "your binary data";
    int dataLength = strlen(binaryData);

    char* pemBase64Data = base64Encode(binaryData, dataLength);
    
    printf("Base64 Encoded PEM Data: %s\n", pemBase64Data);
    
    // Don't forget to free the allocated memory
    free(pemBase64Data);
    
    return 0;
}
