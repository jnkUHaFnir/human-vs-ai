#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int i=0,j;
    char* string[100];
    char line[100];
    FILE *file;
    file = fopen("patt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    while(fgets(line, sizeof line, file)!=NULL) {
        printf("%d %s",i, line);
        string[i] = malloc(strlen(line) + 1); // allocate memory for the line
        strcpy(string[i], line); // copy the contents of the line buffer
        i++;
    }

    for (j=0 ; j<i ; j++) {
        printf("string[%d] %s",j, string[j]);
    }

    // free the allocated memory
    for (j=0; j<i; j++) {
        free(string[j]);
    }

    fclose(file);
    return 0;
}
