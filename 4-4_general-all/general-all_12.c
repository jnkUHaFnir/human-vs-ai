#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 50

int main() {
    FILE *in = fopen("input.txt", "r");
    if (in == NULL) {
        perror("Error opening file");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    int count = 0;

    // Count the number of lines in the file
    while (fgets(line, sizeof(line), in) != NULL) {
        count++;
    }

    printf("Number of lines: %d\n", count);

    // Allocate memory for lines dynamically
    char **lines = (char **)malloc(count * sizeof(char *));
    if (lines == NULL) {
        perror("Memory allocation failed");
        return 1;
    }

    // Reset file pointer to the beginning of the file
    fseek(in, 0, SEEK_SET);

    int i = 0;
    while (fgets(line, sizeof(line), in) != NULL) {
        lines[i] = strdup(line);
        i++;
    }

    // Do something with each line
    for (int j = 0; j < count; j++) {
        // Do something with lines[j]
        printf("Line %d: %s", j, lines[j]);
    }

    // Don't forget to free the dynamically allocated memory
    for (int k = 0; k < count; k++) {
        free(lines[k]);
    }
    free(lines);

    fclose(in);
    return 0;
}
