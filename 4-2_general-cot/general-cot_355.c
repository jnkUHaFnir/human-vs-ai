#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* file = fopen("files.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }

    int num, i;

    // Read the first number which represents the number of integers on the second line
    fscanf(file, "%d", &num);

    // Allocate memory for the integers
    int* p = (int*)malloc(num * sizeof(int));
    if (p == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        fclose(file);
        return 1;
    }

    // Read the integers from the second line
    for (i = 0; i < num; i++) {
        if (fscanf(file, "%d", &p[i]) != 1) {
            fprintf(stderr, "Error reading integers.\n");
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

    // Clean up
    free(p);
    fclose(file);

    return 0;
}
