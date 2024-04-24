#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p = (int *)malloc(10 * sizeof(int)); // Allocate memory for 10 integers
    int i, count = 1;
    if (p == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Input:\n");
    for (i = 0; i < 10 * count; i++) {
        if (scanf("%d", p + i) != 1) {
            printf("Invalid input. Exiting...\n");
            break;
        }
        
        if (*(p + i) == 22) {
            break;
        }
        
        if (i == 9 + (count - 1) * 10) {
            int *temp = realloc(p, (10 + 10 * count) * sizeof(int)); // Reallocate memory
            if (temp == NULL) {
                printf("Memory reallocation failed!\n");
                free(p); // Free previously allocated memory
                return 1;
            }
            p = temp;
            count++;
        }
    }

    printf("\nOutput:\n");
    for (i = 0; i < 10 * count; i++) {
        if (*(p + i) == 22) {
            break;
        }
        printf("%d\n", *(p + i));
    }

    free(p); // Free allocated memory
    return 0;
}
