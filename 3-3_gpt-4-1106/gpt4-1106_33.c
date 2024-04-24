#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/buffer.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/* Function to convert binary data to Base64 */
char* base64_encode(const unsigned char *input, int length) {
    BIO *bmem, *b64;
    BUF_MEM *bptr;
    char *buff;

    b64 = BIO_new(BIO_f_base64());
    bmem = BIO_new(BIO_s_mem());
    b64 = BIO_push(b64, bmem);
    BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL); // Ignore newlines - write everything in one line

    BIO_write(b64, input, length);
    BIO_flush(b64);
    BIO_get_mem_ptr(b64, &bptr);

    // Allocate memory for the encoded buffer
    buff = (char *)malloc(bptr->length + 1);
    if (buff == NULL) {
        BIO_free_all(b64);
        return NULL;
    }

    memcpy(buff, bptr->data, bptr->length);
    buff[bptr->length] = 0; // Null-terminate the string

    BIO_free_all(b64);

    return buff;
}

int main() {
    // Sample binary data
    const unsigned char binary_data[] = {0xDE, 0xAD, 0xBE, 0xEF};
    int binary_length = sizeof(binary_data) / sizeof(unsigned char);

    // Encoding
    char *base64_encoded = base64_encode(binary_data, binary_length);
    if (base64_encoded) {
        printf("Base64 Encoded: %s\n", base64_encoded);
        free(base64_encoded); // Always free allocated memory when done
    } else {
        fprintf(stderr, "Base64 encoding failed\n");
    }
    return 0;
}

Please ensure that you have OpenSSL installed and properly configured on your system before compiling and running this code.
