#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* file = fopen("files.txt", "r");

    int* p = NULL;
    int num = 0;
    int line = 0;
    int value;

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fscanf(file, "%d", &value) == 1) {
        if (line == 0) {
            num = value;
            p = (int*)malloc(num * sizeof(int));
            if (p == NULL) {
                printf("Memory allocation failed.\n");
                return 1;
            }
        } else {
            p[line - 1] = value;
        }

        if (line == num) {
            break;  // Exit the loop once all numbers are read
        }

        line++;
    }

    for (int j = 0; j < num; j++) {
        printf("%d ", p[j]);
    }
    printf("\nNumber of elements: %d\n", num);

    free(p);
    fclose(file);

    return 0;
}
