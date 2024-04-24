#include <stdio.h>

int main() {
    char source[1000000];
    FILE *fp = fopen("TheFile.txt", "r");
    
    if(fp != NULL) {
        size_t bytesRead = fread(source, sizeof(char), sizeof(source), fp);
        if (bytesRead == sizeof(source)) {
            printf("Warning: Input file too large for buffer\n");
        } else {
            // Add null-terminator to mark the end of the content
            source[bytesRead] = '\0';

            // Process the content
            for(size_t x = 0; x < bytesRead; x++) {
                char c = source[x];
                // Process char c
            }
        }
        fclose(fp);
    } else {
        printf("Failed to open file\n");
    }

    return 0;
}
