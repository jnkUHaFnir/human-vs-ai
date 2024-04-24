#include <openssl/evp.h>

int main() {
    unsigned char binary_data[] = {0x01, 0x02, 0x03, 0x04}; // Example binary data
    int binary_data_len = 4;
    
    EVP_ENCODE_CTX *ctx = EVP_ENCODE_CTX_new();
    int pem_buffer_len = EVP_ENCODE_BOUND(binary_data_len);
    char *pem_buffer = (char *)malloc(pem_buffer_len);
    
    EVP_EncodeInit(ctx);
    int pem_output_len = 0;
    EVP_EncodeUpdate(ctx, (unsigned char *)pem_buffer, &pem_output_len, binary_data, binary_data_len);
    
    int final_pem_output_len = 0;
    EVP_EncodeFinal(ctx, (unsigned char *)pem_buffer + pem_output_len, &final_pem_output_len);
    
    pem_output_len += final_pem_output_len;
    pem_buffer[pem_output_len] = '\0';
    
    printf("PEM base64 encoded data: %s\n", pem_buffer);
    
    EVP_ENCODE_CTX_free(ctx);
    free(pem_buffer);
    
    return 0;
}
