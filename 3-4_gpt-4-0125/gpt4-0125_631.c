#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k, item;
    printf("Enter the size of the array:\n");
    scanf("%d", &n);
    int *a = malloc(n * sizeof(*a)); // dynamically allocate memory for n elements

    if (a == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    for (int j = 0; j < n; j++) {
        printf("Enter a[%d] element:\n", j);
        scanf("%d", &a[j]);
    }

    printf("Enter element to insert and position of element (1-based index):\n");
    scanf("%d %d", &item, &k);
    k--; // Adjust to 0-based index

    if (k < 0 || k > n) {
        fprintf(stderr, "Invalid position\n");
        free(a);
        return EXIT_FAILURE;
    }

    // Resizing the array to fit one more element
    a = realloc(a, (n + 1) * sizeof(*a));
    if (a == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    // Shift elements to the right
    for (int j = n; j > k; j--) {
        a[j] = a[j - 1];
    }

    // Insert the new element
    a[k] = item;

    // Print the modified array
    for (int j = 0; j <= n; j++) { // <= n to include the new element
        printf("%d\n", a[j]);
    }

    free(a); // Always free dynamically allocated memory
    return EXIT_SUCCESS;
}
