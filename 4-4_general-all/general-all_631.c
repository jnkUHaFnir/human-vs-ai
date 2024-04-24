#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, j, k, item;
    printf("Enter size of array:\n");
    scanf("%d", &n);

    printf("Enter element to insert and position of element:\n");
    scanf("%d,%d", &item, &k);

    int* a = (int*)malloc(n * sizeof(int)); // dynamically allocate memory for the array

    if (a == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (j = 0; j < n; j++) {
        printf("Enter a[%d] element:\n", j);
        scanf("%d", &a[j]);
    }

    a = (int*)realloc(a, (n + 1) * sizeof(int)); // increase array size by 1

    j = n;
    while (j >= k) {
        a[j] = a[j - 1];
        j = j - 1;
    }

    a[k - 1] = item;

    for (j = 0; j < n + 1; j++) {
        printf("%d\n", a[j]);
    }

    free(a); // free the dynamically allocated memory
    return 0;
}
