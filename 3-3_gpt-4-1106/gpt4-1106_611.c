#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int i = 0, j;
    char *string[100];
    char line[100];
    FILE *file;
    file = fopen("patt", "r");
    if (file == NULL) {
        perror("Unable to open file");
        return EXIT_FAILURE;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        line[strcspn(line, "\n")] = 0; // Remove trailing newline
        printf("%d %s\n", i, line);

        string[i] = malloc(strlen(line) + 1); // Allocate memory for the new string
        if (string[i]) {
            strcpy(string[i], line); // Copy the line into the new string
        } else {
            fprintf(stderr, "Failed to allocate memory for string[%d].\n", i);
            fclose(file);
            return EXIT_FAILURE;
        }

        i++;
    }

    for (j = 0; j < i; j++) {
        printf("string[%d] %s\n", j, string[j]);
        free(string[j]); // Don't forget to free the memory
    }

    fclose(file);
    return 0;
}
