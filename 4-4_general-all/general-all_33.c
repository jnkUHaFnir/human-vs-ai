#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "b64/cdecode.h"
#include "b64/cencode.h"

// Function to encode binary data to base64
char* base64_encode(const unsigned char* input, size_t input_len) {
    base64_encodestate state;
    base64_init_encodestate(&state);

    size_t output_size = (input_len * 2) + 64; // Estimate output size
    char* output = (char*)malloc(output_size);

    int encode_len = base64_encode_block((const char*)input, input_len, output, &state);
    encode_len += base64_encode_blockend(output + encode_len, &state);

    return output;
}

int main() {
    unsigned char binary_data[] = {0xAB, 0xCD, 0xEF, 0x12}; // Sample binary data
    size_t data_len = sizeof(binary_data);

    char* base64_data = base64_encode(binary_data, data_len);
    if (base64_data) {
        printf("Base64 Encoded Data: %s\n", base64_data);
        free(base64_data);
    } else {
        printf("Base64 encoding failed.\n");
    }

    return 0;
}
