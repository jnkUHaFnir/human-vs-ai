#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp = fopen("TheFile.txt", "r");
    if (fp != NULL) {
        // Allocate memory for buffer
        char *source = NULL;
        size_t bufsize = 0;
        size_t index = 0;
        int symbol;

        while ((symbol = getc(fp)) != EOF) {
            // Resize buffer if needed
            if (index >= bufsize - 1) {
                bufsize += 100; // Increase buffer size by a reasonable amount
                source = realloc(source, bufsize);
                if (source == NULL) {
                    // Handle allocation failure
                    fprintf(stderr, "Memory allocation failed\n");
                    fclose(fp);
                    return 1;
                }
            }
            source[index++] = symbol;
        }
        source[index] = '\0'; // Null-terminate the string

        fclose(fp);

        // Process characters
        for (size_t x = 0; source[x] != '\0'; x++) {
            // Process chars
            printf("%c", source[x]); // Example: printing character
        }

        // Free dynamically allocated memory
        free(source);
    } else {
        fprintf(stderr, "Failed to open file\n");
        return 1;
    }

    return 0;
}
