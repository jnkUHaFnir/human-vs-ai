#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/buffer.h>

char* base64_encode(const unsigned char* input, int length) {
    BIO *bio, *b64;
    BUF_MEM *bufferPtr;
    b64 = BIO_new(BIO_f_base64());
    bio = BIO_new(BIO_s_mem());
    bio = BIO_push(b64, bio);
    BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL);
    BIO_write(bio, input, length);
    BIO_flush(bio);
    BIO_get_mem_ptr(bio, &bufferPtr);

    char *output = (char *)malloc(bufferPtr->length + 1);
    memcpy(output, bufferPtr->data, bufferPtr->length);
    output[bufferPtr->length] = '\0';

    BIO_free_all(bio);

    return output;
}

int main() {
    // Sample binary data (replace this with your actual data)
    unsigned char binaryData[] = {0x48, 0x65, 0x6c, 0x6c, 0x6f};
    int binaryDataLength = 5;

    // Encode binary data to base64
    char* base64Data = base64_encode(binaryData, binaryDataLength);
    printf("Base64 encoded data:\n%s\n", base64Data);

    // Don't forget to free the allocated memory after use
    free(base64Data);

    return 0;
}
