#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int i=0, j;
    char* string[100];
    char line[100];
    FILE *file; 
    file = fopen("patt", "r"); 
    if (file == NULL) {
        printf("Failed to open file\n");
        return -1;
    }
    while(fgets(line, sizeof line, file)!=NULL) {
        printf("%d %s",i, line);
        string[i] = malloc(strlen(line) + 1);  // Allocate memory for each line
        if (string[i] == NULL) {
            printf("Failed to allocate memory\n");
            return -1;
        }
        strcpy(string[i],line);  // Copy each line to the newly allocated memory
        i++;
    }
    for (j=0 ; j<i ; j++) {
        printf("string[%d] %s",j, string[j]);
        free(string[j]);  // Remember to free the memory after use
    }
    fclose(file);
    return 0;
}