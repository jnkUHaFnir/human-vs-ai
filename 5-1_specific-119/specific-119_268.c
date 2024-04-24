#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int i=0,j;
    char* string[100];
    char line[100];
    FILE *file; 

    file = fopen("patt", "r"); 
    
    while (fgets(line, sizeof line, file) != NULL) {
        string[i] = malloc(strlen(line) + 1); // +1 for null terminator
        if (string[i] == NULL) {
            fprintf(stderr, "Memory allocation failed");
            exit(1);
        }
        strcpy(string[i], line);
        i++;
    }

    for (j = 0 ; j < i ; j++) {
        printf("string[%d] %s", j, string[j]);
        free(string[j]); // Freeing the allocated memory
    }
    
    fclose(file);
    return 0;
}
