#include <stdio.h>
#include <string.h>
#include <b64/cencode.h>

void convertBinaryToBase64(unsigned char* binaryData, size_t dataSize) {
    FILE *outputFile = fopen("output.pem", "wb");
    FILE *inputFile = fmemopen(binaryData, dataSize, "rb");
    
    base64_encodestate b64state;
    base64_init_encodestate(&b64state);
    
    const int BUF_SIZE = 512;
    char inbuf[BUF_SIZE];
    char outbuf[BUF_SIZE];
    
    int bytes_read, bytes_written;
    
    while ((bytes_read = fread(inbuf, 1, BUF_SIZE, inputFile)) > 0) {
        bytes_written = base64_encode_block(inbuf, bytes_read, outbuf, &b64state);
        fwrite(outbuf, 1, bytes_written, outputFile);
    }
    
    bytes_written = base64_encode_blockend(outbuf, &b64state);
    fwrite(outbuf, 1, bytes_written, outputFile);
    
    fclose(outputFile);
    fclose(inputFile);
}

int main() {
    unsigned char binaryData[] = { /* Your binary data here */ };
    size_t dataSize = sizeof(binaryData);
    
    convertBinaryToBase64(binaryData, dataSize);
    
    return 0;
}
