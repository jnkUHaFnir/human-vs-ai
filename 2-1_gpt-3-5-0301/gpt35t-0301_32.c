#include <openssl/bio.h>
#include <openssl/buffer.h>

// Convert binary data to PEM base64
char* bin_to_pem_base64(unsigned char* data, size_t data_len) {
    BIO *bio, *b64;
    BUF_MEM *mem_buffer;
    
    // Create a base64 filter BIO
    b64 = BIO_new(BIO_f_base64());
    // Create a memory BIO for storing the output
    bio = BIO_new(BIO_s_mem());
    // Chain the BIOs together
    bio = BIO_push(b64, bio);
    // Write the binary data to the base64 BIO
    BIO_write(bio, data, (int)data_len);
    // Flush the BIO to make sure all the data gets encoded
    BIO_flush(bio);
    // Get the pointer to the memory buffer holding the base64 output
    BIO_get_mem_ptr(bio, &mem_buffer);

    // Allocate a null-terminated buffer to hold the base64 output
    char* output = (char*)calloc(mem_buffer->length + 1, 1);
    // Copy the base64 output to the buffer
    memcpy(output, mem_buffer->data, mem_buffer->length);

    // Clean up the BIOs and memory buffer
    BIO_free_all(bio);
    BUF_MEM_free(mem_buffer);

    return output;
}

// Example usage
int main() {
    unsigned char binary_data[] = {0x01, 0x02, 0x03, 0x04, 0x05};
    char* pem_base64 = bin_to_pem_base64(binary_data, sizeof(binary_data));
    printf("%s\n", pem_base64);
    free(pem_base64);
}
