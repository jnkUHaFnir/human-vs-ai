#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_SIZE 1000000

int main() {
    char source[MAX_FILE_SIZE] = {0}; // Initialize buffer with zeros
    int symbol;
    FILE *fp = fopen("TheFile.txt", "r");

    if (fp != NULL) {
        size_t bytesRead = fread(source, sizeof(char), MAX_FILE_SIZE - 1, fp); // Read file contents into buffer
        source[bytesRead] = '\0'; // Null-terminate the string
        fclose(fp);

        for (size_t x = 0; source[x] != '\0'; x++) {
            // Process chars
            char c = source[x];
            // Process each character here
        }
    }

    return 0;
}
