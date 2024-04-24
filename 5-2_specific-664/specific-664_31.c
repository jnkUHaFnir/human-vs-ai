#include <openssl/bio.h>
#include <openssl/evp.h>

char* binary_to_base64(unsigned char* binary_data, int data_len) {
    BIO *bmem, *b64;
    BUF_MEM *bptr;

    b64 = BIO_new(BIO_f_base64());
    bmem = BIO_new(BIO_s_mem());
    b64 = BIO_push(b64, bmem);

    BIO_write(b64, binary_data, data_len);
    BIO_flush(b64);

    BIO_get_mem_ptr(b64, &bptr);

    char* base64_data = (char*)malloc(bptr->length + 1);
    memcpy(base64_data, bptr->data, bptr->length);
    base64_data[bptr->length] = '\0';

    BIO_free_all(b64);

    return base64_data;
}

int main() {
    unsigned char binary_data[] = {0x48, 0x65, 0x6c, 0x6c, 0x6f}; // Example binary data
    int data_len = 5;

    char* base64_data = binary_to_base64(binary_data, data_len);
    printf("Base64 data: %s\n", base64_data);

    free(base64_data);

    return 0;
}
