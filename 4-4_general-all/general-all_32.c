#include <stdio.h>
#include <string.h>
#include <b64/cencode.h>

int main() {
    unsigned char binaryData[] = {0x4A, 0x6F, 0x68, 0x6E, 0x20, 0x44, 0x6F, 0x65}; // Sample binary data
    int binaryDataSize = sizeof(binaryData);
    
    // Calculate the size of the output buffer for base64 encoding
    int base64BufferSize = BASE64_ENCODE_OUT_SIZE(binaryDataSize);
    char *base64Data = (char *)malloc(base64BufferSize);
    
    base64_encodestate state;
    base64_init_encodestate(&state);
    
    int encodedLength = base64_encode_block((const char *)binaryData, binaryDataSize, base64Data, &state);
    encodedLength += base64_encode_blockend(base64Data + encodedLength, &state);
    
    printf("Base64 Encoded data: %s\n", base64Data);
    
    free(base64Data);
    
    return 0;
}
