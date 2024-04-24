#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <b64/cencode.h>

char* binaryToBase64(const unsigned char* binaryData, int dataSize) {
    base64_encodestate state;
    base64_init_encodestate(&state);

    int encodedSize = 1.4 * dataSize + 12; // Calculate approximate size for base64 encoding
    char* base64Data = (char*)malloc(encodedSize);

    int count = base64_encode_block((const char*)binaryData, dataSize, base64Data, &state);
    count += base64_encode_blockend(base64Data + count, &state);

    return base64Data;
}

int main() {
    unsigned char binaryData[] = {0xAB, 0xCD, 0xEF, 0x12, 0x34}; // Sample binary data

    char* base64Data = binaryToBase64(binaryData, sizeof(binaryData));
    printf("Base64 encoded data: %s\n", base64Data);

    free(base64Data);
    
    return 0;
}
