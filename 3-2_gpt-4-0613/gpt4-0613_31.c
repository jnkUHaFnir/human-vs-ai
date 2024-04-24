#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/pem.h>
#include <openssl/rsa.h>

int main()
{
    RSA *rsa = RSA_generate_key(2048, RSA_F4, NULL, NULL);
    BIO *bio = BIO_new(BIO_s_mem());
    PEM_write_bio_RSAPrivateKey(bio, rsa, NULL, NULL, 0, NULL, NULL);

    int keylen = BIO_pending(bio);
    char* pem_key = calloc(keylen+1, 1); 
    BIO_read(bio, pem_key, keylen);

    printf("%s\n", pem_key);
    return 0;
}
#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/buffer.h>
#include <string.h>

char* base64(const unsigned char* input, int length)
{
  BIO *bio, *b64;
  BUF_MEM *bufferPtr;

  b64 = BIO_new(BIO_f_base64());
  bio = BIO_new(BIO_s_mem());
  bio = BIO_push(b64, bio);

  BIO_write(bio, input, length);
  BIO_flush(bio);

  BIO_get_mem_ptr(bio, &bufferPtr);
  BIO_set_close(bio, BIO_NOCLOSE);
  BIO_free_all(bio);

  char* b64text = (*bufferPtr).data;
  return b64text;
}

int main()
{
  unsigned char data[] = {'a','b','c'};
  printf("%s\n",base64(data, sizeof(data)));
  return 0;
}
