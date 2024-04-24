#include <stdio.h>
#include <stdlib.h>
#include <string.h> // For strdup()

int main(void) {
    int i = 0, j;
    char* string[100]; // Array of pointers to char
    char line[100]; // Buffer for fgets
    FILE *file;
    file = fopen("patt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
    
    while(fgets(line, sizeof(line), file) != NULL) {
        printf("%d %s", i, line);
        string[i] = strdup(line); // Make a copy of line
        if (string[i] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            fclose(file);
            // Ideally deallocate any previously allocated strings here
            return 1;
        }
        i++;
    }
    fclose(file);

    for (j = 0; j < i; j++) {
        printf("string[%d] %s", j, string[j]);
        free(string[j]); // Free the allocated memory
    }

    return 0;
}
