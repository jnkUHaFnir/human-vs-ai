#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/bio.h>
#include <openssl/pem.h>

// Function to convert binary data to PEM base64 format
int convertToPEMBase64(const unsigned char* data, size_t dataSize, char** pemBase64Data) {
    BIO* memBio = NULL;
    BIO* base64Bio = NULL;
    BUF_MEM* memBuf = NULL;

    // Create a memory BIO
    memBio = BIO_new(BIO_s_mem());
    if (memBio == NULL) {
        return -1;
    }

    // Create a base64 BIO
    base64Bio = BIO_new(BIO_f_base64());
    if (base64Bio == NULL) {
        BIO_free(memBio);
        return -1;
    }

    // Chain the base64 BIO and memory BIO
    memBio = BIO_push(base64Bio, memBio);

    // Write the binary data to the BIO chain
    if (BIO_write(memBio, data, dataSize) <= 0) {
        BIO_free_all(memBio);
        return -1;
    }

    // Flush the BIO chain
    if (BIO_flush(memBio) <= 0) {
        BIO_free_all(memBio);
        return -1;
    }

    // Get the PEM base64 data from the memory BIO
    BIO_get_mem_ptr(memBio, &memBuf);

    // Allocate memory for the PEM base64 data
    *pemBase64Data = (char*)malloc(memBuf->length + 1);
    if (*pemBase64Data == NULL) {
        BIO_free_all(memBio);
        return -1;
    }

    // Copy the PEM base64 data to the output variable
    memcpy(*pemBase64Data, memBuf->data, memBuf->length);
    (*pemBase64Data)[memBuf->length] = '\0';

    // Free the BIO chain
    BIO_free_all(memBio);

    return 0;
}

int main() {
    unsigned char binaryData[] = {0x01, 0x02, 0x03, 0x04}; // Example binary data
    size_t binaryDataSize = sizeof(binaryData);

    // Convert the binary data to PEM base64 format
    char* pemBase64Data = NULL;
    if (convertToPEMBase64(binaryData, binaryDataSize, &pemBase64Data) == 0) {
        printf("PEM Base64 Data: %s\n", pemBase64Data);
        free(pemBase64Data);
    } else {
        printf("Conversion failed.\n");
    }

    return 0;
}
gcc -o convert convert.c -lssl -lcrypto
