#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* file = fopen("file.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
    
    // Read the number of integers on the first line
    int num;
    if (fscanf(file, "%d", &num) != 1) {
        fprintf(stderr, "Failed to read the number of integers\n");
        fclose(file);
        return 1;
    }

    // Allocate memory for the integers
    int *p = (int *)malloc(num * sizeof(int));
    if (p == NULL) {
        perror("Memory allocation failed");
        fclose(file);
        return 1;
    }

    // Read integers from the second line
    for (int i = 0; i < num; ++i) {
        if (fscanf(file, "%d", &p[i]) != 1) {
            fprintf(stderr, "Failed to read integer number %d\n", i + 1);
            free(p);
            fclose(file);
            return 1;
        }
    }

    // Print the integers
    for (int i = 0; i < num; ++i) {
        printf("%d ", p[i]);
    }
    printf("\n");

    // Clean up
    free(p);
    fclose(file);
    return 0;
}
