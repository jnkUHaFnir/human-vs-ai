#include <openssl/bio.h>
#include <openssl/evp.h>

char* binary_to_pem_base64(const unsigned char* binary_data, size_t data_size)
{
    BIO* mem_bio = BIO_new(BIO_s_mem());
    BIO* b64_bio = BIO_new(BIO_f_base64());
    BIO* pem_bio = BIO_new(BIO_s_mem());

    // Create a bio chain: binary_data -> b64_bio -> pem_bio
    BIO_push(b64_bio, pem_bio);
    BIO_push(mem_bio, b64_bio);

    // Write binary data to the mem_bio
    BIO_write(mem_bio, binary_data, data_size);
    BIO_flush(mem_bio);

    // Flush b64_bio to pem_bio
    BIO_flush(b64_bio);

    // Get the result from pem_bio
    char* pem_data = NULL;
    long pem_size = BIO_get_mem_data(pem_bio, &pem_data);

    // Add the PEM header and footer
    char* final_pem_data = (char*)malloc(pem_size + 28);
    snprintf(final_pem_data, pem_size + 28,
             "-----BEGIN CERTIFICATE-----\n%s\n-----END CERTIFICATE-----\n",
             pem_data);

    // Clean up
    BIO_free_all(mem_bio);
    free(pem_data);

    return final_pem_data;
}
unsigned char binary_data[] = {0x01, 0x02, 0x03, ...};
size_t data_size = sizeof(binary_data);

char* pem_base64_data = binary_to_pem_base64(binary_data, data_size);
