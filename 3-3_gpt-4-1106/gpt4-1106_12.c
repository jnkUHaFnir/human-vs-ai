#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *in = fopen("input.txt", "r");
    if (in == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Count the number of lines
    int count = 0;
    char c;
    while ((c = getc(in)) != EOF) {
        if (c == '\n') {
            count++;
        }
    }

    // Move the file pointer back to the start of the file
    fseek(in, 0, SEEK_SET);

    // Allocate memory for storing lines
    char **lines = malloc((count + 1) * sizeof(char *));
    if (lines == NULL) {
        perror("Memory allocation failed");
        fclose(in);
        return EXIT_FAILURE;
    }

    // Read lines from the file
    char line[50]; // Adjust line size as necessary
    int i = 0;
    while (fgets(line, sizeof(line), in) != NULL) {
        lines[i] = strdup(line);
        if (lines[i] == NULL) {
            perror("Memory allocation failed");
            // Perform cleanup before quitting
            for (int j = 0; j < i; ++j) {
                free(lines[j]);
            }
            free(lines);
            fclose(in);
            return EXIT_FAILURE;
        }
        i++;
    }

    // Use your lines here...
    for (int j = 0; j < count; j++) {
        // Do something with lines[j]
    }

    // Cleanup
    for (int j = 0; j < count; j++) {
        free(lines[j]); // Free each line
    }
    free(lines); // Free the array of pointers
    fclose(in); // Close the file

    return EXIT_SUCCESS;
}
