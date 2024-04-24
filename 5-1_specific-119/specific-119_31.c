#include <stdio.h>
#include <stdlib.h>
#include <openssl/bio.h>
#include <openssl/buffer.h>

// Function to convert binary data to PEM base64
char* bin_to_pem_base64(const unsigned char *input, int length) {
    BIO *bio, *b64;
    BUF_MEM *bufferPtr;
    char *output;

    b64 = BIO_new(BIO_f_base64());
    bio = BIO_new(BIO_s_mem());
    bio = BIO_push(b64, bio);

    BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL);
    BIO_write(bio, input, length);
    BIO_flush(bio);
    
    BIO_get_mem_ptr(bio, &bufferPtr);
    
    output = (char *)malloc(bufferPtr->length + 1);
    memcpy(output, bufferPtr->data, bufferPtr->length);
    output[bufferPtr->length] = '\0';

    BIO_free_all(bio);

    return output;
}

int main() {
    unsigned char binaryData[] = {0x48, 0x65, 0x6c, 0x6c, 0x6f}; // Example binary data
    int length = sizeof(binaryData);

    char* pemBase64 = bin_to_pem_base64(binaryData, length);

    printf("PEM Base64: %s\n", pemBase64);

    free(pemBase64);

    return 0;
}
