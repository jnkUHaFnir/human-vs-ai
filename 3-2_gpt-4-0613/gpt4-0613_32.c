#include <openssl/evp.h>
#include <openssl/bio.h>
#include <openssl/buffer.h>

char* base64(unsigned char* buffer, size_t length)
{
    BIO *bio, *b64;
    BUF_MEM *bufferPtr;

    b64 = BIO_new(BIO_f_base64());
    bio = BIO_new(BIO_s_mem());
    bio = BIO_push(b64, bio);

    BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL); //Ignore newlines - write everything in one line
    BIO_write(bio, buffer, length);
    BIO_flush(bio);
    BIO_get_mem_ptr(bio, &bufferPtr);
    BIO_set_close(bio, BIO_NOCLOSE);
    BIO_free_all(bio);

    char* ret = (char*)(malloc((bufferPtr->length + 1)*sizeof(char)));
    memcpy(ret, bufferPtr->data, bufferPtr->length);
    ret[bufferPtr->length] = '\0';

    return ret;
}
