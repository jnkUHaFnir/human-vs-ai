#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int i = 0, j;
    char line[100];
    char* string[100];
    FILE* file; 
    file = fopen("patt", "r"); 
    while (fgets(line, sizeof line, file) != NULL) {
        printf("%d %s", i, line);
        string[i] = (char*)malloc(strlen(line) + 1); // allocate memory (+1 for null terminator)
        strcpy(string[i], line); // copy the line to allocated memory
        i++;
    }
    for (j = 0; j < i; j++) {
        printf("string[%d] %s", j, string[j]);
        free(string[j]); // free the allocated memory
    }
    fclose(file);
    return 0;
}
