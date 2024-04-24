#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* file = fopen("files.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int num, *p;
    
    // Read the first number which indicates the count of integers to be read
    if (fscanf(file, "%d", &num) != 1 || num <= 0) {
        fprintf(stderr, "Invalid first number in file.\n");
        fclose(file);
        return 1;
    }

    // Allocate memory for the integers
    p = (int*)malloc(num * sizeof(int));
    if (p == NULL) {
        perror("Memory allocation failed");
        fclose(file);
        return 1;
    }

    // Read the integers from the file
    for (int i = 0; i < num; i++) {
        if (fscanf(file, "%d", &p[i]) != 1) {
            fprintf(stderr, "Error reading integer from file.\n");
            free(p);
            fclose(file);
            return 1;
        }
    }

    // Print the integers
    for (int i = 0; i < num; i++) {
        printf("\t%d\t", p[i]);
    }
    printf("\n%d\n", num);

    free(p);
    fclose(file);

    return 0;
}
