#include <stdio.h>
#include <stdlib.h>
#include <string.h> // For strcpy

int main(void) {
    int i=0,j;
    char string[100][100]; // Array of strings
    char line[100];
    FILE* file; 
    file = fopen("patt.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, sizeof line, file) != NULL) {
        printf("%d %s", i, line);
        strcpy(string[i], line); // Copy line to string[i]
        i++;
    }

    for (j = 0; j < i; j++) {
        printf("string[%d] %s", j, string[j]);
    }

    fclose(file);
    return 0;
}
