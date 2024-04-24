#include <openssl/bio.h>
#include <openssl/pem.h>
#include <openssl/evp.h>

int main() {
    unsigned char binaryData[] = { /* Your binary data here */ };
    int binaryDataSize = sizeof(binaryData);

    BIO *mem = BIO_new(BIO_s_mem());
    BIO *b64 = BIO_new(BIO_f_base64());
    mem = BIO_push(b64, mem);

    BIO_write(mem, binaryData, binaryDataSize);
    BIO_flush(mem);

    BUF_MEM *bptr;
    BIO_get_mem_ptr(mem, &bptr);

    // Print base64 encoded PEM data
    printf("-----BEGIN CERTIFICATE-----\n");
    for (size_t i = 0; i < bptr->length; i += 64) {
        for (size_t j = 0; j < 64 && i + j < bptr->length; j++) {
            putchar(bptr->data[i + j]);
        }
        putchar('\n');
    }
    printf("-----END CERTIFICATE-----\n");

    BIO_free_all(mem);

    return 0;
}
