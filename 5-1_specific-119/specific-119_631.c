#include <stdio.h>

int main() {
    int n, j, k, item;
    printf("Enter size of array:\n");
    scanf("%d", &n);

    printf("Enter element to insert and position of element:\n");
    scanf("%d,%d", &item, &k);

    int a[n];

    for (j = 0; j < n; j++) {
        printf("Enter a[%d] element:\n", j);
        scanf("%d", &a[j]);
    }

    if (k < 1 || k > n + 1) {
        printf("Invalid position to insert element.\n");
        return 0;
    }

    j = n - 1;
    while (j >= k - 1) {
        a[j + 1] = a[j];
        j = j - 1;
    }
    a[k - 1] = item;
    
    printf("Array after insertion:\n");
    for (j = 0; j < n; j++) {
        printf("%d\n", a[j]);
    }

    return 0;
}
