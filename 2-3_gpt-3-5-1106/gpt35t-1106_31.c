#include <openssl/evp.h>
#include <openssl/bio.h>
#include <openssl/err.h>

int main() {
    unsigned char binaryData[] = { /* your binary data here */ };
    int binaryDataLength = /* length of your binary data */;

    // Create a BIO object
    BIO *bio = BIO_new(BIO_s_mem());

    // Encode the binary data into base64 and write it to the BIO object
    EVP_EncodeBlock(BIO_ptr(bio), binaryData, binaryDataLength);

    // Get the base64 data from the BIO object
    char *base64Data;
    long base64Length = BIO_get_mem_data(bio, &base64Data);

    // Print the base64 data
    printf("Base64 data: %.*s\n", (int)base64Length, base64Data);

    // Clean up
    BIO_free_all(bio);
    ERR_free_strings();

    return 0;
}
