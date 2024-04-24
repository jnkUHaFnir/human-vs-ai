#include <openssl/bio.h>
#include <openssl/evp.h>

#define MAX_OUTPUT_SIZE 8192

char* binary_to_pem_base64(const unsigned char* binary_data, size_t data_len) {
    BIO *bio_mem = BIO_new(BIO_s_mem());
    BIO *bio_b64 = BIO_new(BIO_f_base64());
    bio_b64 = BIO_push(bio_b64, bio_mem);

    BIO_write(bio_b64, binary_data, data_len);
    BIO_flush(bio_b64);

    char* pem_base64_data = (char*)malloc(MAX_OUTPUT_SIZE);
    memset(pem_base64_data, 0, MAX_OUTPUT_SIZE);

    BIO_read(bio_mem, pem_base64_data, MAX_OUTPUT_SIZE);

    BIO_free_all(bio_b64);

    return pem_base64_data;
}

int main() {
    // Assume you have binary data in unsigned char variable binary_data and its length in data_len
    unsigned char binary_data[] = {0x48, 0x65, 0x6c, 0x6c, 0x6f}; // Example binary data
    size_t data_len = 5;

    char* pem_base64_data = binary_to_pem_base64(binary_data, data_len);
    if (pem_base64_data) {
        printf("PEM Base64 data: %s\n", pem_base64_data);
        free(pem_base64_data);
    }

    return 0;
}
