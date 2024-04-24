#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* file = fopen("file.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int first_num;
    if (fscanf(file, "%d", &first_num) != 1) {
        printf("Error reading first number.\n");
        fclose(file);
        return 1;
    }

    int* p = (int*)malloc(first_num * sizeof(int));
    if (p == NULL) {
        printf("Memory allocation failed.\n");
        fclose(file);
        return 1;
    }

    for (int i = 0; i < first_num; i++) {
        if (fscanf(file, "%d", &p[i]) != 1) {
            printf("Error reading integer.\n");
            free(p);
            fclose(file);
            return 1;
        }
    }

    for (int i = 0; i < first_num; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");

    free(p);
    fclose(file);

    return 0;
}
