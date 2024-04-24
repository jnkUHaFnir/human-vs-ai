#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/buffer.h>
#include <stdio.h>
#include <string.h>

char *base64_encode(const unsigned char *input, int length)
{
    BIO *b64 = BIO_new(BIO_f_base64());
    BIO *bio_mem_buf = BIO_new(BIO_s_mem());
    BIO_push(b64, bio_mem_buf);

    BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL); // Disable newlines in the output
    BIO_write(b64, input, length);
    BIO_flush(b64);

    BUF_MEM *bio_mem_ptr = NULL;
    BIO_get_mem_ptr(b64, &bio_mem_ptr);
    char *base64_encoded = (char *)malloc(bio_mem_ptr->length + 1);
    memcpy(base64_encoded, bio_mem_ptr->data, bio_mem_ptr->length);
    base64_encoded[bio_mem_ptr->length] = '\0';

    BIO_free_all(b64);

    return base64_encoded;
}

int main()
{
    unsigned char data[] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF}; // Your binary data
    int data_len = sizeof(data) / sizeof(unsigned char);

    char *pem_base64 = base64_encode(data, data_len);
    printf("PEM Base64 encoded data: %s\n", pem_base64);

    free(pem_base64);
    return 0;
}
