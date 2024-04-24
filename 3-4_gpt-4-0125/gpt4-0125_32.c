#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>

int main() {
    // Your binary data
    unsigned char binary_data[] = {0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x2c, 0x20, 0x77, 0x6f, 0x72, 0x6c, 0x64, 0x21}; // "Hello, world!"
    size_t binary_data_len = sizeof(binary_data) / sizeof(unsigned char);

    // Calculate the length of the base64 encoded string
    size_t base64_len = 4 * ((binary_data_len + 2) / 3);

    // Allocate memory for the base64 encoded string
    char *base64_data = calloc(base64_len + 1, sizeof(char)); // +1 for the null-terminator

    if (!base64_data) {
        fprintf(stderr, "Failed to allocate memory\n");
        return 1;
    }

    // Convert binary data to base64
    int out_len = EVP_EncodeBlock((unsigned char *)base64_data, binary_data, binary_data_len);

    // Check for errors
    if (out_len < 0) {
        fprintf(stderr, "Failed to encode base64\n");
        free(base64_data);
        return 1;
    }

    printf("Base64 Encoded: %s\n", base64_data);

    // Clean up
    free(base64_data);

    return 0;
}

Remember, when working with real applications, especially those handling sensitive data, always check the return values of library calls for errors. Also, ensure that you manage memory properly to avoid leaks or potential security issues.

Finally, if you're working with PEM encoded data specifically (like certificates, private keys, etc.), OpenSSL provides a wide range of additional functions tailored to handling these formats directly. The example above is for converting arbitrary binary data to Base64 only.
