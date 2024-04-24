#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f;
    long offset_ed;
    char hexes[100]; // Make sure to allocate enough space
    unsigned char bytes[100]; // To store the converted hex to binary

    f = fopen("example.exe", "rb+"); // Open in binary read/write mode

    if(f == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    printf("Specify offset to write: ");
    scanf("%ld", &offset_ed);  //get the offset from the user.

    fseek(f, offset_ed, SEEK_SET);

    printf("Specify HEX bytes to be written to the binary: ");
    scanf("%s", hexes);

    // Convert hex string to binary data
    size_t len = strlen(hexes);
    for(size_t i = 0; i < len/2; i++) {
        bytes[i] = strtol(&hexes[i*2], NULL, 16);
    }

    // Write the binary data to the file
    fwrite(bytes, sizeof(unsigned char), len/2, f);

    fclose(f);

    return 0;
}
