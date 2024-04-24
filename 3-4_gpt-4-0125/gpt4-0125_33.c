#include <openssl/bio.h>
#include <openssl/evp.h>
#include <stdio.h>
#include <string.h>

// Function to encode data to base64
char* encode_base64(const unsigned char* buffer, size_t length) {
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

    // Create a null-terminated string
    char* b64Text = (char*)malloc(bufferPtr->length + 1);
    memcpy(b64Text, bufferPtr->data, bufferPtr->length);
    b64Text[bufferPtr->length] = '\0';

    BIO_free_all(bio);
    
    return b64Text;
}

int main() {
    // Sample binary data
    unsigned char binaryData[] = {0xDE, 0xAD, 0xBE, 0xEF};
    size_t binaryDataLength = sizeof(binaryData) / sizeof(unsigned char);

    // Encode to base64
    char* base64Encoded = encode_base64(binaryData, binaryDataLength);
    printf("Base64 Encoded: %s\n", base64Encoded);

    // Cleanup
    free(base64Encoded);

    return 0;
}
