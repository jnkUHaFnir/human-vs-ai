#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f = fopen("textfile", "r");
    char *line1 = NULL, *line2 = NULL;
    int c;
    size_t n = 0;
    size_t bufferSize = 100; // Initial buffer size

    if (!f) {
        printf("error opening the file\n");
    } else {
        // Allocate memory for the first line
        line1 = malloc(bufferSize);
        if(line1 == NULL){
            printf("Memory allocation failed for line 1\n");
            return -1;
        }
        
        // Read the first line
        while ((c = fgetc(f)) != '\n' && c != EOF) {
            line1[n++] = (char)c;
            // Check if we need to increase the buffer
            if (n >= bufferSize) {
                bufferSize *= 2; // Double the buffer size
                line1 = realloc(line1, bufferSize);
                if(line1 == NULL){
                    printf("Memory reallocation failed for line 1\n");
                    return -1;
                }
            }
        }
        line1[n] = '\0'; // Null-terminate the string

        // Reset for the second line
        n = 0;
        bufferSize = 100;

        // Allocate memory for the second line
        line2 = malloc(bufferSize);
        if(line2 == NULL){
            printf("Memory allocation failed for line 2\n");
            return -1;
        }

        // Read the second line
        while ((c = fgetc(f)) != '\n' && c != EOF) {
            line2[n++] = (char)c;
            // Check if we need to increase the buffer
            if (n >= bufferSize) {
                bufferSize *= 2; // Double the buffer size
                line2 = realloc(line2, bufferSize);
                if(line2 == NULL){
                    printf("Memory reallocation failed for line 2\n");
                    return -1;
                }
            }
        }
        line2[n] = '\0'; // Null-terminate the string

        // Output the lines
        printf("Line 1: %s\n", line1);
        printf("Line 2: %s\n", line2);
    }

    // Clean up
    free(line1);
    free(line2);
    fclose(f);

    return 0;
}
