#include <stdio.h>
#include <string.h>
#include <b64/cencode.h>

int main() {
    const unsigned char binaryData[] = {0x4D, 0x61, 0x6E}; // Example binary data
    const size_t binaryDataLength = sizeof(binaryData);

    base64_encodestate state;
    base64_init_encodestate(&state);

    size_t pemBase64Length = 2 * binaryDataLength; // PEM base64 length is at most 2 * binary data length
    char pemBase64[pemBase64Length];
    
    int encodedLength = base64_encode_block(binaryData, binaryDataLength, pemBase64, &state);
    encodedLength += base64_encode_blockend(pemBase64 + encodedLength, &state);

    printf("PEM base64 encoded data: %s\n", pemBase64);

    return 0;
}
