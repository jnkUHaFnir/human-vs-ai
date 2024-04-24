#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 10; // Example: Number of sorted integers
    int *originalArray = (int *)malloc(sizeof(int) * n);
    
    // Initialize originalArray with sorted integers
    for (int i = 0; i < n; i++) {
        originalArray[i] = i;
    }
    
    while (n > 1) {
        int *newArray = (int *)malloc(sizeof(int) * (n / 2));
        if (newArray == NULL) {
            // Handle memory allocation failure
            printf("Memory allocation failed\n");
            break;
        }
        
        for (int i = 0; i < n / 2; i++) {
            // Merge consecutive elements
            newArray[i] = originalArray[2 * i] + originalArray[2 * i + 1];
            // Print or store the result
            printf("%d ", newArray[i]);
        }
        printf("\n");
        
        // Free the memory allocated for the original array
        free(originalArray);
        // Update n and originalArray for the next iteration
        n = n / 2;
        originalArray = newArray;
    }
    
    // The final result will be in originalArray[0]
    printf("Final result: %d\n", originalArray[0]);
    
    // Free the memory allocated for the final result
    free(originalArray);
    
    return 0;
}
