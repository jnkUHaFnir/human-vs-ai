#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *f;
    char hexes[256]; // Increase buffer size for hex input
    long offset_ed;
    unsigned char buffer[128]; // Buffer to hold actual binary values; size based on the assumption of how large input can be
    int byteCount = 0;

    f = fopen("example.exe", "r+b"); // Open the binary file for reading and writing in binary mode
    if (!f) {
        perror("Failed to open file");
        return 1;
    }

    printf("Specify the offset: ");
    scanf("%ld", &offset_ed); // Get the offset from the user

    fseek(f, offset_ed, SEEK_SET);

    printf("Specify HEX bytes to be written to the binary: ");
    scanf("%s", hexes); // Read hex string from user; resist adding '\n' in scanf

    // Convert hex string to binary
    for (char *pos = hexes; *pos && *(pos+1); pos += 2) {
        sscanf(pos, "%2hhx", &buffer[byteCount++]);
    }

    // Now write the binary values to the file
    fwrite(buffer, sizeof(char), byteCount, f);

    fclose(f);

    return 0;
}
