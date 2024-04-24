#include <stdio.h>
#include <stdlib.h>
#include <b64/cencode.h>

void base64_encode(const unsigned char* input, size_t input_len) {
    struct base64_encode_ctx ctx;
    base64_encode_init(&ctx);

    size_t output_len = base64_encode_max_output_length(input_len);
    char* output = (char*)malloc(output_len);
    if (output == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }

    base64_encode_update(&ctx, input, input_len, output, &output_len);
    base64_encode_final(&ctx, output + output_len);

    printf("Base64 Encoded Data: %s\n", output);

    free(output);
}

int main() {
    unsigned char binary_data[] = {0x4A, 0x7D, 0x2F, 0x01}; // Example binary data

    base64_encode(binary_data, sizeof(binary_data));

    return 0;
}
