#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Required for strdup and strcpy

int main(void) {
    int i = 0, j;
    char* string[100]; // Array of char pointers
    char line[100]; // Buffer to read each line into
    FILE *file;
    file = fopen("patt", "r");
    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }

    while(fgets(line, sizeof line, file) != NULL) {
        printf("%d %s",i, line);
        // Dynamically allocate memory and copy the content of 'line' to 'string[i]'
        string[i] = strdup(line); // 'strdup' duplicates the string and allocates necessary memory
        if (string[i] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            // Clean up already allocated strings
            while (i-- > 0) {
                free(string[i]);
            }
            fclose(file);
            return 1;
        }
        i++;
    }
    fclose(file); // Close the file as soon as you're done with it

    for (j = 0; j < i; j++) {
        printf("string[%d] %s", j, string[j]);
        free(string[j]); // Don't forget to free the allocated memory
    }

    return 0;
}
