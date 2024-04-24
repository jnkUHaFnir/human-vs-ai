#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <b64/cencode.h>

// Function to encode binary data to PEM base64 format
char* encode_base64(unsigned char* input, int input_len) {
    base64_encodestate state;
    base64_init_encodestate(&state);

    int output_len = 2 * input_len; // Base64 encoding increases the data size by a factor of 4/3
    char* output = (char*)malloc(output_len);

    int count = base64_encode_block((char*)input, input_len, output, &state);

    // Finalize the encoding
    count += base64_encode_blockend(output + count, &state);

    return output;
}

int main() {
    unsigned char binary_data[] = {0xDE, 0xAD, 0xBE, 0xEF}; // Example binary data
    int binary_data_len = sizeof(binary_data);

    // Encode binary data to base64
    char* base64_data = encode_base64(binary_data, binary_data_len);

    printf("Base64 Encoded Data: %s\n", base64_data);

    free(base64_data);
    
    return 0;
}
