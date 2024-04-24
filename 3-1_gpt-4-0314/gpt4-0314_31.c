#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/buffer.h>
#include <stdio.h>
#include <string.h>

// Function to encode binary data in base64 using OpenSSL
char *base64encode(const unsigned char *input, int length)
{
  BIO *bio, *b64;
  BUF_MEM *bufferPtr;

  b64 = BIO_new(BIO_f_base64());
  bio = BIO_new(BIO_s_mem());
  bio = BIO_push(b64, bio);

  BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL);
  BIO_write(bio, input, length);
  BIO_flush(bio);

  BIO_get_mem_ptr(bio, &bufferPtr);
  BIO_set_close(bio, BIO_NOCLOSE);

  // Add null-terminator to the buffer
  BUF_MEM_grow(bufferPtr, bufferPtr->length + 1);
  bufferPtr->data[bufferPtr->length] = 0;

  BIO_free_all(bio);

  return bufferPtr->data;
}

int main()
{
  // Sample binary data
  unsigned char data[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};

  char *base64 = base64encode(data, sizeof(data));

  printf("Base64 encoded data: %s\n", base64);

  // Free the memory allocated for the base64 string
  OPENSSL_free(base64);

  return 0;
}

You can then run the program:

```bash
./base64encode
Base64 encoded data: AQIDBAUGBwg=
