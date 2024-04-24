#include <stdio.h>
#include <b64/cencode.h>

#define BUFFER_SIZE 1024

void convertToBase64(unsigned char *inputData, size_t inputDataLength) {
    base64_encodestate state;
    base64_init_encodestate(&state);

    size_t outputDataLength = BUFFER_SIZE * 2; // Assuming output will not exceed this size
    char outputData[outputDataLength];

    int count = base64_encode_block((const char *)inputData, inputDataLength, outputData, &state);
    count += base64_encode_blockend(outputData + count, &state);

    // Write the output to a file or use it as needed
    printf("Base64 encoded data: %s\n", outputData);
}

int main() {
    unsigned char binaryData[] = {0x12, 0x34, 0x56, 0x78}; // Example binary data
    size_t binaryDataLength = sizeof(binaryData);

    convertToBase64(binaryData, binaryDataLength);

    return 0;
}
