#include <stdio.h>
#include <b64/cencode.h>
#include <b64/cdecode.h>

int main() {
    // Sample binary data
    unsigned char binaryData[] = {0x4A, 0x73, 0x68, 0x77, 0x21};

    // Calculate the size of the output buffer
    size_t encodedSize = base64_encoded_size(sizeof(binaryData));

    // Allocate memory for the output buffer
    char *base64Data = (char *)malloc(encodedSize);
    if (base64Data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Encode binary data to base64
    base64_encode(binaryData, sizeof(binaryData), base64Data);

    // Print the base64 encoded data
    printf("Base64 Encoded Data: %s\n", base64Data);

    // Free allocated memory
    free(base64Data);

    return 0;
}

Once you include the `libb64` library, you can compile the code with the following command:

```bash
gcc -o main main.c -lb64
