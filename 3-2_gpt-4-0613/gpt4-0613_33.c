#include <stdio.h>
#include <stdlib.h>
#include <openssl/bio.h>
#include <openssl/evp.h>

char* Base64Encode(const unsigned char* buffer, size_t length) 
{
    BIO *bio, *b64;
    BUF_MEM *bufferPtr;

    b64 = BIO_new(BIO_f_base64());
    bio = BIO_new(BIO_s_mem());
    bio = BIO_push(b64, bio);

    BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL); // Ignore newlines - write everything in one line
    BIO_write(bio, buffer, length);
    BIO_flush(bio);
    BIO_get_mem_ptr(bio, &bufferPtr);
    BIO_set_close(bio, BIO_NOCLOSE);
    BIO_free_all(bio);

    char* base64Data = (char*)malloc((bufferPtr->length + 1) * sizeof(char));
    memcpy(base64Data, bufferPtr->data, bufferPtr->length);
    base64Data[bufferPtr->length] = '\0';

    return base64Data;
}

int main() {
    const unsigned char* binaryData = (unsigned char*)"Hello, world!";
    char* base64Data = Base64Encode(binaryData, strlen((const char*)binaryData));

    printf("%s\n", base64Data);
    free(base64Data);

    return 0;
}
