#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int i = 0, j;
    char* string[100];
    char line[100];
    FILE *file; 
    file = fopen("patt.txt", "r"); // corrected the filename
    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }

    while (fgets(line, sizeof line, file) != NULL) {
        string[i] = malloc(strlen(line) + 1); // allocate memory for each line
        if (string[i] == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            return 1;
        }
        stripNewline(line); // remove the newline character
        strcpy(string[i], line); // copy the line content to allocated memory
        i++;
    }

    for (j = 0; j < i; j++) {
        printf("string[%d] %s\n", j, string[j]);
        free(string[j]); // free the allocated memory
    }

    fclose(file);
    return 0;
}
void stripNewline(char *str) {
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}
