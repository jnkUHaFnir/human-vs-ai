#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *in = fopen("file.txt", "r");
    if (in == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Count the number of lines
    int count = 0;
    char c;
    while ((c = fgetc(in)) != EOF) {
        if (c == '\n')
            count++;
    }
    // Add 1 to the count to account for the last line
    count++;

    printf("\nNUMBER OF LINES = %d \n", count);

    // Initialize the array
    char **lines = (char **)malloc(count * sizeof(char *));
    // Reset file pointer to the beginning
    fseek(in, 0, SEEK_SET);

    // Read the lines and store them in the array
    char line[50];
    int i = 0;
    while (fgets(line, 50, in) != NULL) {
        // Remove the newline character from the line
        line[strcspn(line, "\n")] = 0;

        lines[i] = strdup(line);
        i++;
    }

    // Do something with the lines
    for (int j = 0; j < count; j++) {
        printf("Line %d: %s\n", j, lines[j]);
    }

    // Free the memory
    for (int j = 0; j < count; j++) {
        free(lines[j]);
    }
    free(lines);
    fclose(in);

    return 0;
}
