#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LINE_LENGTH 100

int main(void) {
    int i = 0, j;
    char* string[MAX_LINES];
    char line[MAX_LINE_LENGTH];
    FILE* file;
    
    file = fopen("patt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line, sizeof line, file) != NULL) {
        printf("%d %s", i, line);
        string[i] = malloc(strlen(line) + 1); // Allocating memory for the line
        strcpy(string[i], line); // Copying the content of line to the allocated memory
        i++;
    }

    for (j = 0; j < i; j++) {
        printf("string[%d] %s", j, string[j]);
        free(string[j]); // Freeing the allocated memory
    }

    fclose(file);
    return 0;
}
