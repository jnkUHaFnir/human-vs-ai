#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p = (int*)malloc(10 * sizeof(int));
    if (!p) {
        printf("Memory allocation failed\n");
        return 1;
    }

    int i, count = 1;
    printf("Input:\n");
    for (i = 0; ; i++) {
        scanf("%d", p + i);
        
        if (*(p + i) == 22) {
            break;
        }

        if (i == 9 + (count - 1) * 10) {
            int *temp = (int*)realloc(p, (10 + 10 * count) * sizeof(int));
            if (!temp) {
                printf("Memory reallocation failed\n");
                free(p);
                return 1;
            }
            p = temp;
            count++;
        }
    }

    printf("\nOutput:\n");
    for (int j = 0; j < i; j++) {
        printf("%d\n", *(p + j));
    }

    free(p);
    return 0;
}
