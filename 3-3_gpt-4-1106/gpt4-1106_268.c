#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Needed for strcpy

int main(void) {
    int i = 0, j;
    char* strings[100]; // Changed the name to strings for clarity
    char line[100];
    FILE *file;
    file = fopen("patt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1; // Return an error code if the file couldn't be opened
    }
    while(fgets(line, sizeof line, file) != NULL) {
        printf("%d %s", i, line);
        // Allocate memory for the new string, including space for the null terminator
        strings[i] = malloc(strlen(line) + 1);
        // Check if memory allocation succeeded
        if (strings[i] == NULL) {
            perror("Error allocating memory");
            fclose(file);
            return 1;
        }
        // Copy line into newly allocated space
        strcpy(strings[i], line);
        i++;
    }
    fclose(file);

    for (j = 0; j < i; j++) {
        printf("strings[%d] %s", j, strings[j]);
        free(strings[j]); // Free the memory allocated for each string
    }

    return 0;
}
