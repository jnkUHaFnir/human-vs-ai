#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // Include the header for string functions

int main(void) {
    int i = 0, j;
    char* string[100];  // Array of pointers to char
    char line[100];     // Buffer to hold each line read from the file
    FILE *file; 
    file = fopen("patt", "r"); 
    if (!file) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }
    while(fgets(line, sizeof line, file) != NULL) {
        printf("%d %s", i, line);
        string[i] = strdup(line);  // Duplicate the line and store the pointer
        if (!string[i]) {
            fprintf(stderr, "Memory allocation failed.\n");
            return 1;  // Clean-up and error checking should be added here
        }
        i++;
    }
    fclose(file);
    
    for (j = 0; j < i; j++) {
        printf("string[%d] %s", j, string[j]);
    }
    
    // Release the allocated memory
    for (j = 0; j < i; j++) {
        free(string[j]);
    }
    
    return 0;
}
