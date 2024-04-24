#include <stdio.h>
#include <openssl/bio.h>
#include <openssl/pem.h>

void convertBinaryToPEMBase64(unsigned char *binaryData, size_t binaryDataSize) {
    BIO *bio_mem = BIO_new(BIO_s_mem());
    BIO *bio_b64 = BIO_new(BIO_f_base64());
    BIO *bio_out = BIO_new_fp(stdout, BIO_NOCLOSE);

    BIO_set_flags(bio_b64, BIO_FLAGS_BASE64_NO_NL);
    bio_out = BIO_push(bio_b64, bio_out);
    BIO_write(bio_mem, binaryData, binaryDataSize);
    BIO_flush(bio_mem);
    BIO_ctrl(bio_out, BIO_CTRL_RESET, 0, NULL);
    BIO_ctrl(bio_out, BIO_C_SET_BUF_MEM, BIO_CLOSE, NULL, bio_mem->ptr);
    BIO_flush(bio_out);

    BIO_free_all(bio_out);
}

int main() {
    unsigned char binaryData[] = {0xDE, 0xAD, 0xBE, 0xEF}; // Example binary data
    size_t binaryDataSize = sizeof(binaryData);

    convertBinaryToPEMBase64(binaryData, binaryDataSize);

    return 0;
}
