#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int i = 0;
    char* string[100];
    char line[100];
    FILE *file;

    file = fopen("patt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line, sizeof line, file) != NULL) {
        printf("%d %s", i, line);
        
        // Allocate memory for the current line
        string[i] = malloc(strlen(line) + 1); // +1 for the null terminator
        if (string[i] == NULL) {
            perror("Memory allocation failed");
            return 1;
        }
        
        // Copy the line to the allocated memory
        strcpy(string[i], line);
        i++;
    }

    for (int j = 0; j < i; j++) {
        printf("string[%d] %s", j, string[j]);
        // Free the allocated memory for each line
        free(string[j]);
    }

    fclose(file);
    return 0;
}
