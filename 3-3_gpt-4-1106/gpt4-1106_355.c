#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("file.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    int num;
    // Read the number from the first line
    if (fscanf(file, "%d", &num) != 1) {
        fclose(file);
        fprintf(stderr, "Failed to read the number from the first line\n");
        return -1;
    }
     
    // Allocate memory to store the numbers
    int* p = (int*)malloc(num * sizeof(int));

    if (p == NULL) {
        fclose(file);
        fprintf(stderr, "Memory allocation failed\n");
        return -1;
    }

    // Read numbers from the second line
    for (int i = 0; i < num; i++) {
        if (fscanf(file, "%d", &p[i]) != 1) {
            free(p);
            fclose(file);
            fprintf(stderr, "Failed to read number %d from the second line\n", i + 1);
            return -1;
        }
    }

    // Do something with the numbers
    for (int i = 0; i < num; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");

    // Clean up
    free(p);
    fclose(file);

    return 0;
}
