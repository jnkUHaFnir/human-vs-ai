#include <stdio.h>
#include <stdlib.h> // For exit() and malloc()

int main() {
    char *source;
    long length;
    FILE *fp = fopen("TheFile.txt", "r");
    if (fp != NULL) {
        // Seek to the end of the file
        fseek(fp, 0, SEEK_END);
        // Get the current file position (now at the end), thus the size
        length = ftell(fp);
        // Seek back to the start of the file
        fseek(fp, 0, SEEK_SET);

        // Allocate memory for the entire content
        source = malloc(length + 1);
        if (source == NULL) {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }

        // Read the file into memory
        if (fread(source, 1, length, fp) != length) {
            perror("Failed to read the file");
            free(source);
            exit(EXIT_FAILURE);
        }

        // Null-terminate the string
        source[length] = '\0';

        fclose(fp);

        // Now, you can process the buffer
        for (int x = 0; source[x] != '\0'; x++) {
            // Process chars
            // Example: Print characters
            putchar(source[x]);
        }

        free(source); // Don't forget to free the memory
    } else {
        perror("Failed to open the file");
    }

    return 0;
}
