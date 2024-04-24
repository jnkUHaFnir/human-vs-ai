#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p = (int *)malloc(10 * sizeof(int));
    if (p == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    int i, count = 1;
    printf("Input:\n");
    for (i = 0; i < 10 * count; i++) {
        if (scanf("%d", p + i) != 1) {
            fprintf(stderr, "Invalid input\n");
            return 1;
        }
        if (*(p + i) == 22) {
            break;
        }
        if (i == 9 + (count - 1) * 10) {
            int *temp = realloc(p, (10 + 10 * count) * sizeof(int));
            if (temp == NULL) {
                fprintf(stderr, "Memory reallocation failed\n");
                free(p);
                return 1;
            }
            p = temp;
            count++;
        }
    }

    printf("\nOutput:\n");
    i = 0;
    while (*(p + i) != 22) {
        printf("%d\n", *(p + i));
        i++;
    }

    free(p);
    return 0;
}
