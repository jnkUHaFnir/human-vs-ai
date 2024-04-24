#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char base64_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

char *binary_to_base64(unsigned char *data, size_t input_length) {
    size_t output_length = 4 * ((input_length + 2) / 3);
    char *encoded_data = malloc(output_length + 1);
    if (encoded_data == NULL) return NULL;

    for (size_t i = 0, j = 0; i < input_length;) {
        uint32_t octet_a = i < input_length ? data[i++] : 0;
        uint32_t octet_b = i < input_length ? data[i++] : 0;
        uint32_t octet_c = i < input_length ? data[i++] : 0;

        uint32_t triple = (octet_a << 0x10) + (octet_b << 0x08) + octet_c;

        encoded_data[j++] = base64_table[(triple >> 3 * 6) & 0x3F];
        encoded_data[j++] = base64_table[(triple >> 2 * 6) & 0x3F];
        encoded_data[j++] = i > input_length + 1 ? '=' : base64_table[(triple >> 1 * 6) & 0x3F];
        encoded_data[j++] = i > input_length + 2 ? '=' : base64_table[(triple >> 0 * 6) & 0x3F];
    }

    encoded_data[output_length] = '\0';
    return encoded_data;
}

int main() {
    unsigned char binary_data[] = {0xDE, 0xAD, 0xBE, 0xEF};
    size_t binary_data_length = 4;

    char *base64_data = binary_to_base64(binary_data, binary_data_length);
    if (base64_data != NULL) {
        printf("Base64: %s\n", base64_data);
        free(base64_data);
    }

    return 0;
}
