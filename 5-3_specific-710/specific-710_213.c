#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("file.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    int num_elements, line = 0;

    // Read line by line
    while (fscanf(file, "%d", &num_elements) == 1) {
        line++;

        if (line == 2) {
            int* p = (int*)malloc(num_elements * sizeof(int));
            if (p == NULL) {
                fprintf(stderr, "Memory allocation failed\n");
                return 1;
            }

            // Read integers
            for (int i = 0; i < num_elements; i++) {
                fscanf(file, "%d", &p[i]);
            }

            // Print the integers
            for (int i = 0; i < num_elements; i++) {
                printf("%d ", p[i]);
            }
            printf("\n");

            free(p);
        }
    }

    fclose(file);
    return 0;
}
