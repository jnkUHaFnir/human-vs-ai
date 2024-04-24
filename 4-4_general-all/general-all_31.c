#include <openssl/bio.h>
#include <openssl/evp.h>

char* binaryToBase64PEM(const unsigned char* data, size_t data_len) {
    BIO *bmem, *b64;
    BUF_MEM *bptr;

    // Create a base64 filter/output BIO
    b64 = BIO_new(BIO_f_base64());
    BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL);

    // Create a memory BIO to hold the base64 data
    bmem = BIO_new(BIO_s_mem());
    b64 = BIO_push(b64, bmem);

    // Write the binary data to the base64 BIO
    BIO_write(b64, data, (int)data_len);
    BIO_flush(b64);

    // Get the base64 data from the memory BIO
    BIO_get_mem_ptr(b64, &bptr);

    // Allocate memory for the base64 data and copy it
    char *base64_data = (char*)malloc(bptr->length + 1);
    memcpy(base64_data, bptr->data, bptr->length);
    base64_data[bptr->length] = '\0';

    // Free the BIOs
    BIO_free_all(b64);

    return base64_data;
}

int main() {
    unsigned char binary_data[] = {0x4D, 0x61, 0x6E}; // Sample binary data
    size_t binary_data_len = sizeof(binary_data);

    char* pem_base64_data = binaryToBase64PEM(binary_data, binary_data_len);
    
    printf("PEM Base64 Data: %s\n", pem_base64_data);

    free(pem_base64_data); // Don't forget to free the allocated memory

    return 0;
}
