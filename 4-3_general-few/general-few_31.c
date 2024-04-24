#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/pem.h>

void binaryToPEMBase64(const unsigned char* binaryData, size_t binaryDataLength) {
    BIO *bio_mem = BIO_new(BIO_s_mem());
    BIO *bio_base64 = BIO_new(BIO_f_base64());
    BIO_set_flags(bio_base64, BIO_FLAGS_BASE64_NO_NL);
    BIO *bio = BIO_push(bio_base64, bio_mem);

    BIO_write(bio, binaryData, binaryDataLength);
    BIO_flush(bio);

    BUF_MEM *bufferPtr;
    BIO_get_mem_ptr(bio_mem, &bufferPtr);

    fwrite(bufferPtr->data, 1, bufferPtr->length, stdout);
    
    BIO_free_all(bio);
}

int main() {
    unsigned char binaryData[] = { 0x48, 0x65, 0x6c, 0x6c, 0x6f }; // Sample binary data
    
    binaryToPEMBase64(binaryData, sizeof(binaryData));

    return 0;
}
