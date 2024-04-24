#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void DoThis(int n, int arr[n], int level);

// Global variable to store the target input array to find
int target[] = {1, 2, 4, 3};
int foundLevel = -1;

int main() {
    int a[] = {2, 3, 4, 1};

    // Call the DoThis function with input 'a' at level 1
    DoThis(4, a, 1);

    // Check if the target array was found and print the level
    if (foundLevel != -1) {
        printf("Target array found at level: %d\n", foundLevel);
    } else {
        printf("Target array not found\n");
    }

    return 0;
}

void DoThis(int n, int arr[n], int level) {
    if (n <= 1) {
        return;
    }

    // Dynamic allocation of the array of pointers
    int **output = malloc(n * sizeof(*output));
    
    for (int i = 0; i < n; i++) {
        int *copy = malloc(n * sizeof(*copy));

        // Copy the array elements
        for (int j = 0; j < n; j++) {
            copy[j] = arr[j];
        }

        // Swap elements
        int temp = copy[i];
        copy[i] = copy[(i + 1) % n];
        copy[(i + 1) % n] = temp;

        // Assign the copied array to the output
        output[i] = copy;

        // Output the swapped array elements
        printf("Level %d, Output %d: ", level, i + 1);
        for (int k = 0; k < n; k++) {
            printf("%d, ", copy[k]);
        }
        printf("\n");

        // Check if the target array is found
        int isEqual = 1;
        for (int k = 0; k < n; k++) {
            if (copy[k] != target[k]) {
                isEqual = 0;
                break;
            }
        }

        if (isEqual) {
            foundLevel = level;
            return;
        }
    }

    // Recursively call DoThis for each output array
    for (int i = 0; i < n; i++) {
        DoThis(n, output[i], level + 1);
    }

    // Free memory for current level output array
    for (int i = 0; i < n; i++) {
        free(output[i]);
    }
    free(output);
}
