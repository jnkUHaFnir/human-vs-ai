#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *f;
    long offset_ed;
    char hexes[100]; // Assuming max input length of 100 characters

    // Open the file in binary mode
    f = fopen("example.exe", "r+b");
    if (f == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Get the offset from the user
    printf("Enter the offset to write hex bytes: ");
    scanf("%ld", &offset_ed);

    // Move the file pointer to the specified offset
    fseek(f, offset_ed, SEEK_SET);

    // Get the hex bytes from the user
    printf("Specify HEX bytes to be written to the binary: ");
    scanf("%s", hexes);

    // Convert the hex string to binary representation
    size_t len = strlen(hexes);
    if (len % 2 != 0) {
        printf("Hex string length must be even.\n");
        fclose(f);
        return 1;
    }

    for (size_t i = 0; i < len; i += 2) {
        char *byte_str = &hexes[i];
        char byte = (char)strtol(byte_str, NULL, 16);
        fwrite(&byte, sizeof(char), 1, f);
    }

    fclose(f);

    return 0;
}
