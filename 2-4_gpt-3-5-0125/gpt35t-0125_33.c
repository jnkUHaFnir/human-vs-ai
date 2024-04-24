#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/bio.h>
#include <openssl/evp.h>

void convertToBase64(unsigned char *data, int data_len) {
    BIO *base64_bio, *mem_bio;
    BUF_MEM *mem_bio_mem;
    char *base64_data;

    base64_bio = BIO_new(BIO_f_base64());
    BIO_set_flags(base64_bio, BIO_FLAGS_BASE64_NO_NL);
    mem_bio = BIO_new(BIO_s_mem());
    BIO_push(base64_bio, mem_bio);

    BIO_write(base64_bio, data, data_len);
    BIO_flush(base64_bio);

    BIO_get_mem_ptr(mem_bio, &mem_bio_mem);
    base64_data = (char *)malloc(mem_bio_mem->length);
    memcpy(base64_data, mem_bio_mem->data, mem_bio_mem->length - 1);
    base64_data[mem_bio_mem->length - 1] = 0;

    printf("Base64 Encoded Data:\n%s\n", base64_data);

    free(base64_data);
    BIO_free_all(base64_bio);
}

int main() {
    unsigned char binary_data[] = "Hello, World!";
    int binary_data_len = strlen((char *)binary_data);

    printf("Input Data:\n%s\n", binary_data);

    convertToBase64(binary_data, binary_data_len);

    return 0;
}
gcc your_program.c -o your_program -lssl -lcrypto
