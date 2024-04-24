#include <stdio.h>
#include <openssl/bio.h>
#include <openssl/evp.h>
#include <string.h>

// Function to convert binary data to base64-encoded string
char *base64_encode(const unsigned char *input, int length) {
    BIO *bmem, *b64;
    BUF_MEM *bptr;

    b64 = BIO_new(BIO_f_base64());
    BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL); // We don't want newlines
    bmem = BIO_new(BIO_s_mem());
    b64 = BIO_push(b64, bmem);

    BIO_write(b64, input, length);
    BIO_flush(b64);
    BIO_get_mem_ptr(b64, &bptr);

    // Allocate memory for the encoded buffer (+1 for null-termination)
    char *buff = (char *)malloc(bptr->length + 1);
    if (buff == NULL) {
        BIO_free_all(b64);
        return NULL; // Memory allocation failed
    }

    memcpy(buff, bptr->data, bptr->length);
    buff[bptr->length] = 0; // Null-terminate the string

    BIO_free_all(b64);

    return buff;
}

int main() {
    // Example binary data
    const unsigned char binary_data[] = {0x48, 0x65, 0x6c, 0x6c, 0x6f};

    // Size of the binary data
    size_t binary_data_size = sizeof(binary_data);

    // Convert to base64
    char *base64_encoded = base64_encode(binary_data, binary_data_size);
    if (base64_encoded) {
        printf("Base64 Encoded: %s\n", base64_encoded);
        free(base64_encoded); // Remember to free the allocated memory
    } else {
        fprintf(stderr, "Failed to encode data to base64.\n");
    }

    return 0;
}

Keep in mind that the function `base64_encode` allocates memory for the base64 encoded string, which you need to free yourself after you're done using it.
