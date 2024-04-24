#include <openssl/bio.h>
#include <openssl/evp.h>

char *binary_to_base64(const unsigned char *buf, size_t size) {
    BIO *bio, *b64;
    BUF_MEM *bufferPtr;

    b64 = BIO_new(BIO_f_base64());
    bio = BIO_new(BIO_s_mem());
    bio = BIO_push(b64, bio);

    BIO_write(bio, buf, size);
    BIO_flush(bio);

    BIO_get_mem_ptr(bio, &bufferPtr);

    char *result = (char *)malloc(bufferPtr->length + 1);
    memcpy(result, bufferPtr->data, bufferPtr->length);
    result[bufferPtr->length] = '\0';

    BIO_free_all(bio);

    return result;
}
