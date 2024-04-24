#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *f;
    char input[100];
    long offset_ed;
    
    // Open the file in binary mode
    f = fopen("example.exe", "r+b");
    if (f == NULL) {
        perror("Error opening file");
        return 1;
    }
    
    printf("Specify offset (in hex) to start writing the bytes: ");
    scanf("%lx", &offset_ed); // Read offset as hexadecimal
    
    fseek(f, offset_ed, SEEK_SET);
    
    printf("Specify HEX bytes to be written to the binary: ");
    scanf("%s", input);

    // Convert the hex input string to byte values
    int len = strlen(input) / 2;
    unsigned char *bytes = malloc(len);
    for (int i = 0; i < len; i++) {
        sscanf(&input[2*i], "%2hhx", &bytes[i]);
    }

    // Write the byte values to the file
    fwrite(bytes , sizeof(unsigned char), len, f);

    free(bytes);
    fclose(f);

    return 0;
}
