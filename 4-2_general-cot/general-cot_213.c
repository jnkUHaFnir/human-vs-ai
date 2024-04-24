#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* file = fopen("files.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int first_num;
    if (fscanf(file, "%d", &first_num) != 1) {
        perror("Error reading first number from file");
        fclose(file);
        return 1;
    }

    int* p = (int*)malloc(first_num * sizeof(int));
    if (p == NULL) {
        perror("Memory allocation failed");
        fclose(file);
        return 1;
    }

    for (int j = 0; j < first_num; j++) {
        if (fscanf(file, "%d", &p[j]) != 1) {
            perror("Error reading integer from file");
            fclose(file);
            free(p);
            return 1;
        }
    }

    for (int j = 0; j < first_num; j++) {
        printf("\t%d\t", p[j]);
    }
    printf("\n%d\n", first_num);

    free(p);
    fclose(file);

    return 0;
}
