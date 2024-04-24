#include <stdio.h>
#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/buffer.h>

int Base64Encode(const unsigned char* buffer, size_t length, char** b64text) { 
    BIO *bio, *b64;
    BUF_MEM *bufferPtr;
    b64 = BIO_new(BIO_f_base64());
    bio = BIO_new(BIO_s_mem());
    bio = BIO_push(b64, bio);

    BIO_write(bio, buffer, length);
    BIO_flush(bio);
    BIO_get_mem_ptr(bio, &bufferPtr);
    BIO_set_close(bio, BIO_NOCLOSE);

    *b64text=(*bufferPtr).data;
    long b64TextSize = (*bufferPtr).length;

    BIO_free_all(bio);
    return b64TextSize; // return the length of the base64 encoded string
}

int main() {
    unsigned char data[] = {0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x20, 0x57, 0x6f, 0x72, 0x6c, 0x64}; // "Hello World" in binary
    size_t dataLength = sizeof(data) / sizeof(data[0]);
    char* encodedData;

    if (Base64Encode(data, dataLength, &encodedData)) {
        printf("Base64 Encoded Data: %s\n", encodedData);
        // Once you're done with the encoded data, you will need to free it.
        // In this case, because OpenSSL allocated the memory for the encoded string with the `BUF_MEM` structure,
        // and then you assigned its pointer to `encodedData`, OpenSSL should be responsible for the memory management.
        // Normally, you would use `BUF_MEM_free()` to release the memory, but since OpenSSL's internal calls
        // leave the pointer in a potentially unsafe state, don't use `free(encodedData)` immediately.
        // If you allocate the memory yourself for `BUF_MEM` and manage it, then you would be responsible for freeing it.
    } else {
        fprintf(stderr, "Error encoding data to base64\n");
    }

    return 0;
}
