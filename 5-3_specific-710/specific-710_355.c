#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* file = fopen("file.txt", "r");
    if (!file) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    int first_num, j = 0;
    int* p = NULL;  // Initialize pointer to NULL
    int num_read = fscanf(file, "%d", &first_num);  // Read the first integer
    if (num_read != 1) {
        fprintf(stderr, "Error reading first number\n");
        fclose(file);
        return 1;
    }

    p = (int*)malloc(first_num * sizeof(int));  // Allocate memory based on the first number
    if (!p) {
        fprintf(stderr, "Memory allocation failed\n");
        fclose(file);
        return 1;
    }

    for(j = 0; j < first_num; j++) {
        if(fscanf(file, "%d", &p[j]) != 1) {  // Read integers into the allocated memory
            fprintf(stderr, "Error reading integers\n");
            free(p);
            fclose(file);
            return 1;
        }
    }

    for(j = 0; j < first_num; j++) {
        printf("\t%d\t", p[j]);  // Print the integers
    }
    printf("\n%d\n", first_num);

    free(p);  // Free the allocated memory
    fclose(file);

    return 0;
}
