#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Create the original array and fill it with sorted integers
    int *originalArray = (int*)malloc(n * sizeof(int));
    printf("Enter %d sorted integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &originalArray[i]);
    }

    // Loop to repeatedly half the array
    while (n > 1) {
        // Create a new array of half the size
        int *newArray = (int*)malloc((n / 2) * sizeof(int));

        // Add consecutive two numbers and fill the new array
        for (int i = 0; i < n; i += 2) {
            if (i + 1 < n) {
                newArray[i / 2] = originalArray[i] + originalArray[i + 1];
            } else {
                newArray[i / 2] = originalArray[i];
            }
        }

        // Output the current array after halving
        printf("Current array (size %d):\n", n / 2);
        for (int i = 0; i < n / 2; i++) {
            printf("%d ", newArray[i]);
        }
        printf("\n");

        // Free the original array
        free(originalArray);

        // Make the new array the original array for the next iteration
        originalArray = newArray;
        n = n / 2;
    }

    // Free the final array and exit
    free(originalArray);
    return 0;
}
