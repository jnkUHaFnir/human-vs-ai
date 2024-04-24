#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <b64/cencode.h>

int main() {
    unsigned char binaryData[] = { /* your binary data here */ };
    size_t binaryDataSize = sizeof(binaryData);

    // Calculate size of the base64 output (4 bytes for every 3 bytes of input + potential padding)
    size_t pemBase64Size = 4 * ((binaryDataSize + 2) / 3);

    // Allocate space for the base64 output
    char* pemBase64Data = (char*)malloc(pemBase64Size + 1); // +1 for null terminator
    if (pemBase64Data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Perform base64 encoding
    base64_encodestate state;
    base64_init_encodestate(&state);
    int encLen = base64_encode_block((const char*)binaryData, binaryDataSize, pemBase64Data, &state);
    encLen += base64_encode_blockend(pemBase64Data + encLen, &state);

    // Null terminate the base64 output
    pemBase64Data[encLen] = '\0';

    // Print the PEM base64 data
    printf("PEM base64 encoded data:\n%s\n", pemBase64Data);

    // Clean up
    free(pemBase64Data);

    return 0;
}
