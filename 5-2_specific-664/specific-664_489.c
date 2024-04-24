#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int i = 0, j;
    char* string[100];
    char line[100];
    FILE *file; 

    file = fopen("patt", "r"); 
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line, sizeof line, file) != NULL) {
        // Allocate memory for the line
        string[i] = malloc(strlen(line) + 1);
        if (string[i] == NULL) {
            perror("Error allocating memory");
            return 1;
        }

        // Copy the line into the allocated memory
        strcpy(string[i], line);

        printf("%d %s", i, line);
        i++;
    }

    for (j = 0; j < i; j++) {
        printf("string[%d] %s", j, string[j]);
        free(string[j]); // Free the allocated memory
    }

    fclose(file);
    return 0;
}
