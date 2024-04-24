#include <openssl/bio.h>
#include <openssl/pem.h>
unsigned char *binary_data = your_binary_data;
int binary_data_len = your_binary_data_length;
BIO *mem_bio = BIO_new(BIO_s_mem());
BIO_write(mem_bio, binary_data, binary_data_len);
BIO *b64_bio = BIO_new(BIO_f_base64());
BIO *bio = BIO_new_fp(stdout, BIO_NOCLOSE);
bio = BIO_push(b64_bio, mem_bio);
char *base64_data;
long base64_len = BIO_get_mem_data(mem_bio, &base64_data);
printf("Base64 Encoded Data:\n%s\n", base64_data);

// Free the BIO objects
BIO_free_all(bio);
