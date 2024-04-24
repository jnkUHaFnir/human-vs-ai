#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *f = fopen("example.exe", "r+b"); // Open the file in read/write mode

    if (f == NULL) {
        perror("Error opening file");
        return 1;
    }

    long offset_ed;
    printf("Specify offset from the beginning of the file: ");
    scanf("%ld", &offset_ed); // Get the offset from the user

    fseek(f, offset_ed, SEEK_SET);

    char hexes[255]; // Assuming a maximum of 255 characters for hex input
    printf("Specify HEX bytes to be written to the binary: ");
    scanf("%s", hexes);

    // Convert hex string to binary data
    size_t len = strlen(hexes);
    if (len % 2 != 0) {
        fprintf(stderr, "Error: Hex string length must be even\n");
        fclose(f);
        return 1;
    }

    unsigned char *bytes = (unsigned char *)malloc(len / 2);
    for (size_t i = 0; i < len; i += 2) {
        if (sscanf(&hexes[i], "%2hhx", &bytes[i / 2]) != 1) {
            fprintf(stderr, "Error: Invalid hex character\n");
            free(bytes);
            fclose(f);
            return 1;
        }
    }

    // Write the binary data to the file
    fwrite(bytes, sizeof(unsigned char), len / 2, f);

    free(bytes);
    fclose(f);

    return 0;
}
