#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *f;
    long offset_ed;
    char hexes[100]; // assuming the user input will not exceed 100 characters
    unsigned char buffer[100]; // buffer to hold processed hex bytes

    f = fopen("example.exe", "r+b"); // open the file in read/write binary mode

    if (f == NULL) {
        perror("Error opening file");
        return 1;
    }

    printf("Enter the offset from which point you want to replace the bytes: ");
    scanf("%ld", &offset_ed);

    fseek(f, offset_ed, SEEK_SET);
    
    // Read hexadecimal bytes input as a string
    printf("Specify HEX bytes to be written to the binary: ");
    scanf("%s", hexes);
    
    // Convert input string to hexadecimal bytes
    size_t len = strlen(hexes);
    if (len % 2 != 0) {
        fprintf(stderr, "Invalid input length\n");
        fclose(f);
        return 1;
    }
    
    for (size_t i = 0, j = 0; i < len; i += 2, j++) {
        sscanf(&hexes[i], "%2hhx", &buffer[j]); // read 2 characters as a byte from hexes
    }

    // Write the processed bytes to the file
    fwrite(buffer, sizeof(unsigned char), len / 2, f);

    fclose(f);

    printf("Bytes replaced successfully.\n");

    return 0;
}
