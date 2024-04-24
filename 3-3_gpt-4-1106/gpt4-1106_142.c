#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
  
    if (n <= 0) {
        printf("Number of elements must be positive.\n");
        return 1;
    } 

    // Allocate memory for the array
    int *array = malloc(n * sizeof(int));
  
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Assume the array is sorted and populated with some values
    for (int i = 0; i < n; ++i) {
        array[i] = i + 1; // Example: Fill array with 1, 2, ..., n
    }

    // Process the array and halve its size until one element remains
    while (n > 1) {
        int new_size = n / 2; // Determine the new array size
        
        // Optionally, if you have to do operations with odd number handling
        if (n % 2 != 0) {
            new_size += 1;  // Accommodate the last element if n is odd
        }

        // Allocate a new array for the pairwise sums
        int *new_array = malloc(new_size * sizeof(int));
        
        if (new_array == NULL) {
            printf("Memory allocation failed.\n");
            free(array);  // Clean up previously allocated memory
            return 1;
        }

        // Calculate pairwise sums and perform other operations
        for (int i = 0; i < n / 2; ++i) {
            new_array[i] = array[2 * i] + array[2 * i + 1];
            // Here, store the computed data (pairwise sums) as needed
        }

        // If n is odd, copy the last element
        if (n % 2 != 0) {
            new_array[new_size - 1] = array[n - 1];
        }

        // Free the old array and replace it with the new one
        free(array);
        array = new_array;
        n = new_size; // Update the size of the array for the next iteration

        // Optionally, print the intermediate array for verification
        for (int i = 0; i < n; ++i) {
            printf("%d ", array[i]);
        }
        printf("\n");
    }

    // The final number after reduction
    printf("Final number: %d\n", array[0]);

    // Clean up the final array
    free(array);

    return 0;
}
