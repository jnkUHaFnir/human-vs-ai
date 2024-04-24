#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert two hex characters to a single byte
unsigned char hexToByte(const char* hex) {
    unsigned int byte;
    sscanf(hex, "%2x", &byte);
    return (unsigned char)byte;
}

int main() {
    FILE *f;
    long offset_ed;
    char hexes[256]; // Here we assume no more than 256 hex characters will be input.
    unsigned char buffer[128]; // This buffer will store the converted hex values.

    // Make sure to open the file for reading and writing (updating)
    f = fopen("example.exe", "rb+");
    if (!f) {
        perror("Error opening file");
        return 1;
    }

    printf("Enter offset: ");
    scanf("%ld", &offset_ed);
    fseek(f, offset_ed, SEEK_SET);

    printf("Specify HEX bytes to be written to the binary: ");
    scanf("%s", hexes);

    // Calculate the length of the input hex array and convert to bytes
    size_t hexLen = strlen(hexes);
    if (hexLen % 2 != 0) {
        fprintf(stderr, "Hex string should have an even number of characters.\n");
        fclose(f);
        return 1;
    }
    size_t byteCount = hexLen / 2;
    for(size_t i = 0; i < byteCount; ++i) {
        char hexPair[3] = { hexes[i*2], hexes[i*2 + 1], '\0' };
        buffer[i] = hexToByte(hexPair);
    }

    fwrite(buffer, sizeof(unsigned char), byteCount, f);
    fclose(f);

    printf("Bytes successfully written.\n");
    return 0;
}
