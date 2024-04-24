#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LINE_LENGTH 100

int main(void) {
    int i = 0;
    char* string[MAX_LINES];
    char line[MAX_LINE_LENGTH];
    FILE *file; 

    file = fopen("patt", "r"); 
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line, sizeof line, file) != NULL && i < MAX_LINES) {
        string[i] = malloc(strlen(line) + 1);
        if (string[i] == NULL) {
            perror("Memory allocation failed");
            return 1;
        }
        strcpy(string[i], line);
        printf("%d %s", i, string[i]);
        i++;
    }

    for (int j = 0; j < i; j++) {
        printf("string[%d] %s", j, string[j]);
        free(string[j]); // Free allocated memory
    }
    
    fclose(file);
    return 0;
}
