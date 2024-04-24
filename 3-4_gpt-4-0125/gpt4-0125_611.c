#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Include for strcpy and strdup functions

int main(void) {
    int i = 0, j;
    char* string[100]; // Array to store addresses of lines
    char line[100]; // Buffer to temporarily hold each line
    FILE *file;

    file = fopen("patt", "r");
    if (file == NULL) {
        perror("Unable to open file");
        return 1;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%d %s", i, line);
        string[i] = (char*)malloc(strlen(line) + 1); // +1 for the null terminator
        if (string[i] == NULL) { // Check for malloc failure
            perror("Failed to allocate memory");
            // Free already allocated memory before exiting
            for (int k = 0; k < i; k++) {
                free(string[k]);
            }
            fclose(file);
            return 1;
        }
        strcpy(string[i], line); // Copy line to newly allocated memory
        i++;
    }

    for (j = 0; j < i; j++) {
        printf("string[%d] %s", j, string[j]);
        free(string[j]); // Free the memory allocated for this string
    }

    fclose(file);
    return 0;
}
