#include <stdio.h>
#include <openssl/bio.h>
#include <openssl/evp.h>

int Base64Encode(const unsigned char* buffer, size_t length, char** b64text) {
    BIO *bio, *b64;
    BUF_MEM *bufferPtr;

    b64 = BIO_new(BIO_f_base64());
    if (!b64) return 1; // Failed to initialize, handle error appropriately
    bio = BIO_new(BIO_s_mem());
    if (!bio) { // Failed to initialize, handle error appropriately
        BIO_free_all(b64);
        return 1;
    }
    bio = BIO_push(b64, bio);

    BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL); // Ignore newlines - write everything in one line
    BIO_write(bio, buffer, length);
    BIO_flush(bio);
    BIO_get_mem_ptr(bio, &bufferPtr);
    BIO_set_close(bio, BIO_NOCLOSE);

    *b64text = (char*)malloc(bufferPtr->length + 1);
    memcpy(*b64text, bufferPtr->data, bufferPtr->length);
    (*b64text)[bufferPtr->length] = 0; // Null-terminator

    BIO_free_all(bio);

    return 0; // Success
}

int main() {
    const unsigned char binary_data[] = "This is binary data, not text!"; // Your binary data
    char *base64_encoded = NULL;

    if (Base64Encode(binary_data, sizeof(binary_data) - 1, &base64_encoded) == 0) {
        printf("Base64 Encoded Data: %s\n", base64_encoded);
    } else {
        printf("Failed to encode data.\n");
    }

    free(base64_encoded);
    
    return 0;
}
