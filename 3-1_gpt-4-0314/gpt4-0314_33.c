#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/buffer.h>
char* base64_encode(const unsigned char* input, int length) {
    BIO *bio, *b64;
    BUF_MEM *bufferPtr;

    b64 = BIO_new(BIO_f_base64());
    bio = BIO_new(BIO_s_mem());
    bio = BIO_push(b64, bio);

    BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL); // Ignore newlines - write everything in one line
    BIO_write(bio, input, length);
    BIO_flush(bio);

    BIO_get_mem_ptr(bio, &bufferPtr);
    BIO_set_close(bio, BIO_NOCLOSE);
    BIO_free_all(bio);

    char *base64_encoded = (char *)malloc((bufferPtr->length + 1) * sizeof(char));
    memcpy(base64_encoded, bufferPtr->data, bufferPtr->length);
    base64_encoded[bufferPtr->length] = '\0';

    BUF_MEM_free(bufferPtr);

    return base64_encoded;
}
int main() {
    unsigned char data[] = {0x01, 0x02, 0x03, 0x04, 0x05};
    int length = sizeof(data);

    char *pem_base64 = base64_encode(data, length);

    printf("PEM Base64: %s\n", pem_base64);

    free(pem_base64);

    return 0;
}
