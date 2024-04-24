#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE *file = fopen("file.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Failed to open the file.\n");
        return 1;
    }

    int num, *p, i;

    // Read the first number from the file
    if (fscanf(file, "%d", &num) != 1) {
        fprintf(stderr, "Failed to read the number of integers.\n");
        fclose(file);
        return 1;
    }

    // Allocate memory for the integers
    p = (int *)malloc(num * sizeof(int));
    if (p == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        fclose(file);
        return 1;
    }

    // Read integers from the file and store them in the allocated memory
    for (i = 0; i < num; i++) {
        if (fscanf(file, "%d", &p[i]) != 1) {
            fprintf(stderr, "Failed to read integer %d.\n", i);
            free(p);
            fclose(file);
            return 1;
        }
    }

    // Print the integers
    for (i = 0; i < num; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");

    // Clean up allocated memory and close the file
    free(p);
    fclose(file);

    return 0;
}
