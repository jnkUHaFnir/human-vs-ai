#include <stdio.h>
#include <string.h>
#include <b64/cencode.h>

int main() {
    const unsigned char binaryData[] = {0x48, 0x65, 0x6C, 0x6C, 0x6F}; // Sample binary data
    const size_t binaryDataSize = sizeof(binaryData);

    base64_encodestate state;
    base64_init_encodestate(&state);

    size_t outputBufferSize = 2 * binaryDataSize + 10; // PEM base64 output buffer size estimation
    char* PEMBase64Data = (char*)malloc(outputBufferSize);

    int encodedLength = base64_encode_block(binaryData, binaryDataSize, PEMBase64Data, &state);
    encodedLength += base64_encode_blockend(PEMBase64Data + encodedLength, &state);

    printf("PEM base64 encoded data: %s\n", PEMBase64Data);

    free(PEMBase64Data);

    return 0;
}
