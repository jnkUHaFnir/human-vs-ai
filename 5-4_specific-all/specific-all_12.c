#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 50

int main() {
    FILE *in = fopen("file.txt", "r");
    if (in == NULL) {
        perror("Error opening file");
        return -1;
    }

    int count = 1;
    char c; 
    while ((c = fgetc(in)) != EOF) {
        if (c == '\n') {
            count++;
        }
    }
    rewind(in); // Reset file pointer to the beginning

    printf("NUMBER OF LINES = %d \n", count); 

    char **lines = (char**)malloc(count * sizeof(char*)); // Allocate memory for array of pointers
    if (lines == NULL) {
        perror("Memory allocation failed");
        return -1;
    }

    char line[MAX_LINE_LENGTH];
    int i = 0;
    
    while (fgets(line, MAX_LINE_LENGTH, in) != NULL && i < count) {
        lines[i] = strdup(line);
        i++;
    }
    
    for (int j = 0; j < count; j++) {
        printf("Line %d: %s", j, lines[j]);
        free(lines[j]); // Free memory allocated by strdup
    }

    free(lines); // Free memory allocated for array of pointers
    fclose(in);
    
    return 0;
}
