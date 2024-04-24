#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f;
    long offset_ed;
    char hexes[10];
    
    // Open the binary file for reading and writing in binary mode
    f = fopen("example.exe", "rb+");
    if (f == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read the offset from the user
    printf("Enter the offset from which to write the hex values: ");
    scanf("%ld", &offset_ed);
    
    // Move the file pointer to the specified offset
    fseek(f, offset_ed, SEEK_SET);

    // Read the hex bytes as string
    printf("Specify HEX bytes to be written to the binary (without spaces): ");
    scanf("%9s", hexes);

    // Convert the hex string to bytes and write them to the file
    for (int i = 0; hexes[i] && hexes[i + 1]; i += 2) {
        char byte[3] = {hexes[i], hexes[i + 1], '\0'};
        unsigned int val;
        sscanf(byte, "%x", &val);
        fputc((unsigned char)val, f);
    }

    fclose(f);
    
    return 0;
}
