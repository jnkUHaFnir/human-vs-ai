#include <openssl/evp.h>
#include <openssl/bio.h>
#include <openssl/pem.h>
char* convertToPEMBase64(const unsigned char* data, size_t length);
char* convertToPEMBase64(const unsigned char* data, size_t length) {
    EVP_ENCODE_CTX* ctx;
    BIO* bioMem, *bioB64;
    BUF_MEM* mem;
    char* pemBase64;

    ctx = EVP_ENCODE_CTX_new();
    EVP_EncodeInit(ctx);

    bioMem = BIO_new(BIO_s_mem());
    bioB64 = BIO_new(BIO_f_base64());
    BIO_push(bioB64, bioMem);

    // Encode the binary data into base64 format
    EVP_EncodeUpdate(ctx, (unsigned char*)bioMem->ptr, &(bioMem->num_write), data, length);
    EVP_EncodeFinal(ctx, (unsigned char*)bioMem->ptr + bioMem->num_write, &(bioMem->num_write));

    BIO_get_mem_ptr(bioMem, &mem);
    pemBase64 = (char*)malloc(mem->length + 1);
    strncpy(pemBase64, mem->data, mem->length);
    pemBase64[mem->length] = '\0';

    EVP_ENCODE_CTX_free(ctx);
    BIO_free_all(bioMem);
    free(mem);
    return pemBase64;
}
unsigned char binaryData[10] = { /* Your binary data */ };
size_t dataLength = sizeof(binaryData);

char* pemBase64 = convertToPEMBase64(binaryData, dataLength);

// Use the PEM base64-encoded string as required

free(pemBase64); // Free the allocated memory
