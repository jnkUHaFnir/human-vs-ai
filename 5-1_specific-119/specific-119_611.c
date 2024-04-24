#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int i=0,j;
    char* string[100];
    char line[100];
    FILE *file; 
    file = fopen("patt", "r"); 
    while(fgets(line, sizeof line, file) != NULL) {
        // Allocate memory for the line
        string[i] = malloc(strlen(line) + 1); // +1 for null terminator
        strcpy(string[i], line);
        i++;
    }

    // Print the lines
    for (j = 0 ; j < i ; j++) {
        printf("string[%d] %s", j, string[j]);
        // Free the allocated memory
        free(string[j]);
    }

    fclose(file);
    return 0;
}
