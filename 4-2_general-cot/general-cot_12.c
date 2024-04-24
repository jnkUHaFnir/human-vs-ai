#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 50

int main() {
    char line[MAX_LINE_LENGTH];
    int count = 0;

    FILE *in = fopen("input.txt", "r");
    if (in == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, in) != NULL) {
        count++;
    }

    // Reset file pointer to beginning of file
    fseek(in, 0, SEEK_SET);

    char **lines = malloc(count * sizeof(char *));
    if (lines == NULL) {
        perror("Memory allocation failed");
        return 1;
    }

    int i = 0;
    while (fgets(line, MAX_LINE_LENGTH, in) != NULL) {
        lines[i] = strdup(line);
        i++;
    }

    for (int j = 0; j < count; j++) {
        // Do something with each line
        printf("Line %d: %s", j, lines[j]);
    }

    // Free memory for each line
    for (int j = 0; j < count; j++) {
        free(lines[j]);
    }

    // Free memory for lines array
    free(lines);

    fclose(in);

    return 0;
}
