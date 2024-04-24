#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_SIZE 1000000

int main() {
    char source[MAX_FILE_SIZE];
    
    FILE *fp = fopen("TheFile.txt", "r");
    if (fp != NULL) {
        size_t bytesRead = fread(source, 1, MAX_FILE_SIZE, fp);
        source[bytesRead] = '\0'; // Null-terminate the buffer
        
        // Check for read errors
        if (ferror(fp)) {
            // Handle read error
            perror("Error reading file");
        }
        
        fclose(fp);
        
        for (size_t i = 0; i < bytesRead; i++) {
            char c = source[i];
            // Process chars
        }
    } else {
        perror("Error opening file");
    }
    
    return 0;
}
