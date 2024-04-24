#include <openssl/pem.h>
void convertToPEMBase64(const unsigned char* data, size_t length, BIO *bio) {
    // Create a memory BIO
    BIO *b64 = BIO_new(BIO_f_base64());
    BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL);
    
    // Create a BIO to write to the provided BIO
    BIO *bioOut = BIO_new(BIO_s_bio());
    BIO_set_write_buf_size(bioOut, 4096);
    BIO_push(b64, bioOut);

    // Write the binary data to the base64 BIO
    BIO_write(b64, data, length);
    BIO_flush(b64);
    
    // Write the base64 data to the provided BIO
    BIO_write(bio, bioOut, BIO_pending(bioOut));
    
    // Cleanup
    BIO_free_all(b64);
}
unsigned char binaryData[] = {0x01, 0x02, 0x03, 0x04, 0x05};
size_t length = sizeof(binaryData);

// Create a memory BIO to hold base64 data
BIO *bio = BIO_new(BIO_s_mem());

// Convert binary data to PEM base64
convertToPEMBase64(binaryData, length, bio);

// Write base64 data to a file
FILE* file = fopen("output.pem", "wb");
BIO_write_filename(bio, "output.pem");
fclose(file);

// Cleanup
BIO_free_all(bio);
gcc yourfile.c -o yourprogram -lcrypto
