#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int i = 0, j;
    char* string[100];
    char line[100];
    FILE* file;
    file = fopen("patt", "r");

    while (fgets(line, sizeof line, file) != NULL) {
        printf("%d %s", i, line);

        // Allocate memory for each string
        string[i] = (char*)malloc(strlen(line) + 1);
        strcpy(string[i], line);
        i++;
    }

    for (j = 0; j < i; j++) {
        printf("string[%d] %s", j, string[j]);

        // Free the memory allocated for each string
        free(string[j]);
    }

    fclose(file);
    return 0;
}
