#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int i=0,j;
    char* string[100];
    char line[100];
    FILE *file; 
    file = fopen("patt", "r"); 
    while(fgets(line, sizeof line, file)!=NULL) {
        printf("%d %s",i, line);
        string[i] = malloc(strlen(line) + 1); // Allocate memory for each string
        strcpy(string[i], line); // Copy the contents of the line array to the allocated memory
        i++;
    }
    for (j=0 ; j<i ; j++) {
        printf("string[%d] %s",j, string[j]);
        free(string[j]); // Free the allocated memory
    }
    fclose(file);
    return 0;
}
