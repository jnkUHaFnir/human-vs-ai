#include <stdio.h>
#include <stdlib.h>

int main() {
    char source[1000000];
    int c;
    size_t index = 0;

    FILE *fp = fopen("TheFile.txt", "r");
    if(fp != NULL) {
        while ((c = getc(fp)) != EOF && index < sizeof(source) - 1) {
            source[index++] = (char)c;
        }
        source[index] = '\0'; // Add null terminator at the end of the string
        fclose(fp);

        // Process characters from the buffer
        for(size_t x = 0; source[x] != '\0'; x++) {
            // Process chars
        }

    } else {
        // Handle file opening error
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    return 0;
}
