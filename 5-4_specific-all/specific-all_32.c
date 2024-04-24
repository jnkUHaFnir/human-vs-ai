#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <b64/cencode.h>

void base64_encode(const unsigned char *input, int input_len) {
    struct base64_encode_ctx ctx;
    base64_encode_init(&ctx);

    // Calculate the output buffer size (4/3 times the input size)
    int output_len = input_len * 4 / 3 + 4;
    char *output = (char *)malloc(output_len);

    if (output) {
        int count = base64_encode_update(&ctx, input, input_len, output);
        count += base64_encode_final(&ctx, output + count);

        printf("Base64 Encoded Data:\n%s\n", output);

        free(output);
    }
}

int main() {
    unsigned char binary_data[] = {0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x20, 0x57, 0x6f, 0x72, 0x6c, 0x64};
    int binary_data_len = sizeof(binary_data);

    base64_encode(binary_data, binary_data_len);

    return 0;
}
