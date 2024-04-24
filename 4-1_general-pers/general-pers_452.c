#include <stdio.h>

int main() {
    FILE *f;
    long offset_ed;
    unsigned char hexes[100]; // Assuming a maximum of 100 bytes for hex instructions
    
    f = fopen("example.exe", "rb+"); // Open in read/write binary mode

    if (f == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }

    printf("Offset to start writing: ");
    scanf("%ld", &offset_ed);

    fseek(f, offset_ed, SEEK_SET);

    printf("Specify HEX bytes to be written to the binary: ");
    scanf("%s", hexes); // Read hex instructions into hexes buffer

    size_t hex_len = strlen((char*)hexes); // Get the length of hex instructions

    // Convert hex string to binary and write to file
    for (size_t i = 0; i < hex_len; i += 2) {
        unsigned int byte;
        sscanf((char*)&hexes[i], "%2x", &byte); // Read 2 characters as a hex value
        fputc(byte, f); // Write the byte to the file
    }

    fclose(f);
    return 0;
}
