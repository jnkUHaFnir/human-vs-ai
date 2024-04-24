#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *in = fopen("input.txt", "r");
    if (in == NULL) {
        perror("Error opening file");
        return 1;
    }

    int count = 0;
    char c;

    // Count the number of lines in the file
    while ((c = getc(in)) != EOF) {
        if (c == '\n') {
            count++;
        }
    }
    rewind(in); // Reset file pointer to beginning of file

    printf("NUMBER OF LINES = %d\n", count);

    // Dynamically allocate memory for the lines array based on count
    char **lines = (char **)malloc(count * sizeof(char *));
    if (lines == NULL) {
        perror("Error allocating memory");
        return 1;
    }

    for (int i = 0; i < count; i++) {
        char line[50];
        if (fgets(line, sizeof(line), in) != NULL) {
            lines[i] = strdup(line);
        } else {
            perror("Error reading line");
            return 1;
        }
    }

    // Do something with each line
    for (int j = 0; j < count; j++) {
        printf("Line %d: %s", j, lines[j]);
        // Do something with each line
    }

    // Free the allocated memory
    for (int i = 0; i < count; i++) {
        free(lines[i]);
    }
    free(lines);

    fclose(in);
    return 0;
}
