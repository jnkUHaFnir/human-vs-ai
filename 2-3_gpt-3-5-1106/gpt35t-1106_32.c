#include <openssl/bio.h>
#include <openssl/evp.h>

void convertToBase64(unsigned char *data, int dataLength) {
    BIO *bio, *b64;
    BUF_MEM *bptr;

    b64 = BIO_new(BIO_f_base64());
    bio = BIO_new(BIO_s_mem());
    bio = BIO_push(b64, bio);

    BIO_write(bio, data, dataLength);
    BIO_flush(bio);
    BIO_get_mem_ptr(bio, &bptr);

    // bptr->data contains the base64 encoded data

    BIO_free_all(bio);
}

int main() {
    // Your binary data
    unsigned char binaryData[] = { /* your binary data */ };
    int dataLength = sizeof(binaryData);

    convertToBase64(binaryData, dataLength);

    return 0;
}
