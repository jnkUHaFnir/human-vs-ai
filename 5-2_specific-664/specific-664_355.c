#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 100

int main() {
    FILE* file = fopen("file.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    int line_number = 2; // Specific line number to read
    int num_elements, i;

    // Skip lines until the desired line
    for (int i = 1; i < line_number; i++) {
        if (fgets(line, sizeof(line), file) == NULL) {
            fprintf(stderr, "Error: Line %d not found\n", line_number);
            fclose(file);
            return 1;
        }
    }

    // Read the line with integers
    if (fgets(line, sizeof(line), file) == NULL) {
        fprintf(stderr, "Error reading line %d\n", line_number);
        fclose(file);
        return 1;
    }

    // Parse the integers from the line
    char* token = strtok(line, " ");
    if (token == NULL || sscanf(token, "%d", &num_elements) != 1) {
        fprintf(stderr, "Invalid number of elements\n");
        fclose(file);
        return 1;
    }

    int* elements = (int*)malloc(num_elements * sizeof(int));
    if (elements == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        fclose(file);
        return 1;
    }

    for (i = 0; i < num_elements; i++) {
        token = strtok(NULL, " ");
        if (token == NULL || sscanf(token, "%d", &elements[i]) != 1) {
            fprintf(stderr, "Error parsing element %d\n", i);
            free(elements);
            fclose(file);
            return 1;
        }
    }

    // Print the elements
    printf("Elements: ");
    for (i = 0; i < num_elements; i++) {
        printf("%d ", elements[i]);
    }
    printf("\n");

    free(elements);
    fclose(file);
    return 0;
}
