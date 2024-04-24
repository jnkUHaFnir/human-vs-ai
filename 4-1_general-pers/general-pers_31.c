#include <b64/cencode.h>
#include <stdio.h>
#include <string.h>
#include <b64/cencode.h>

#define INPUT_SIZE 100 // Update this with the size of your binary data

int main() {
    unsigned char binaryData[INPUT_SIZE]; // Your binary data
    // Fill binaryData with your binary data

    // Output buffer for base64 data
    unsigned char base64Data[2 * INPUT_SIZE]; // Base64 data will always be at most 2 times the size of binary data

    // Prepare a base64 stream
    base64_encodestate state;
    base64_init_encodestate(&state);

    // Encode the binary data to base64
    int encodedLength = base64_encode_block(binaryData, INPUT_SIZE, base64Data, &state);
    encodedLength += base64_encode_blockend((char *) base64Data + encodedLength, &state);

    // Null-terminate the base64 string
    base64Data[encodedLength] = '\0';

    // Print the base64 data
    printf("Base64 Encoded Data: %s\n", base64Data);

    return 0;
}
