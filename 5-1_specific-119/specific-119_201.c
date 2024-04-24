#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p = (int*)malloc(10 * sizeof(int));
    int i, count = 1;

    if (p == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Input :\n");
    for (i = 0; i < 10 * count; i++) {
        scanf("%d", p + i);
        if (*(p + i) == 22) {
            break;
        }
        if (i == 9 + (count - 1) * 10) {
            int* temp = (int*)realloc(p, (10 + 10 * count) * sizeof(int));
            if (temp == NULL) {
                printf("Memory reallocation failed.\n");
                free(p); // Freeing the original pointer before exit
                return 1;
            }
            p = temp;
            count++;
        }
    }

    printf("\nOutput :\n");
    i = 0;
    while (*(p + i) != 22) {
        printf("%d\n", *(p + i));
        i++;
    }

    free(p); // Freeing the memory allocated before exit
    return 0;
}
