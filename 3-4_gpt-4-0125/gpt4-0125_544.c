#include <stdio.h>
#include <stdlib.h>

void bar(char *fileName, int *pX) {
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", fileName);
        return; // Always good to check if the file was opened successfully
    }

    char *buffer = malloc(15 * sizeof(char)); // Here should be sizeof(char) since buffer is a char array.
    if (fgets(buffer, 15, fp) != NULL) {
        sscanf(buffer, "%d", pX); // Use sscanf to read from buffer, and note pX is already a pointer
    } else {
        printf("Error reading from file %s\n", fileName);
    }
    free(buffer);
    fclose(fp);
}
