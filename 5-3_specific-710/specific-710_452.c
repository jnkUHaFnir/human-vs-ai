#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f;
    long offset_ed;
    char hexes[100]; // Assuming a maximum length for hex instructions

    f = fopen("example.exe", "rb+"); // Opening the file in read/write mode

    if (f == NULL) {
        perror("Error opening file");
        return 1;
    }

    printf("Specify offset from the beginning of the file: ");
    scanf("%ld", &offset_ed);
    
    fseek(f, offset_ed, SEEK_SET);
    
    printf("Specify HEX bytes to be written to the binary: ");
    scanf("%s", hexes);

    // Convert the hex string to binary representation
    size_t len = strlen(hexes);
    for (size_t i = 0; i < len; i += 2) {
        unsigned int byte;
        sscanf(&hexes[i], "%2X", &byte);
        fwrite(&byte, sizeof(unsigned char), 1, f);
    }

    fclose(f);

    return 0;
}
