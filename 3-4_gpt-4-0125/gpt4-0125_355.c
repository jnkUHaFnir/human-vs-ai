#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* file = fopen("numbers.txt", "r");
    if (file == NULL) {
        perror("Unable to open file");
        return -1;
    }

    int num;
    // Step 2: Read the first number.
    if (fscanf(file, "%d", &num) != 1) {
        fclose(file);
        fprintf(stderr, "Failed to read the number of integers.\n");
        return -1;
    }

    // Step 3: Allocate memory.
    int *p = malloc(num * sizeof(int));
    if (p == NULL) {
        fclose(file);
        fprintf(stderr, "Failed to allocate memory.\n");
        return -1;
    }

    // Step 4: Read the subsequent integers.
    for (int i = 0; i < num; i++) {
        if (fscanf(file, "%d", &p[i]) != 1) {
            free(p);
            fclose(file);
            fprintf(stderr, "Failed to read integer %d.\n", i + 1);
            return -1;
        }
    }

    // Step 5: Do something with the loaded data.
    for (int i = 0; i < num; i++) {
        printf("%d\n", p[i]);
    }

    // Step 6: Clean up.
    free(p);
    fclose(file);
    return 0;
}
