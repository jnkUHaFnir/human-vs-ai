#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to swap two integers
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to generate permutations and check for the desired output
int DoThis(int n, int arr[n]) {
    int l = n;
    int *copy = malloc(l * sizeof(*copy));
    memcpy(copy, arr, l * sizeof(*copy));

    int level = 1;
    
    while (1) {
        int found = 1;
        for (int i = 0; i < l; i++) {
            if (copy[i] != i + 1) {
                found = 0;
                break;
            }
        }
        if (found) {
            break;
        }

        int j = (level) % l;
        swap(&copy[j-1], &copy[j]);
        
        level++;
    }

    free(copy);

    return level;
}

int main() {
    int a[] = {2, 3, 4, 1}; // Input array
    int result = DoThis(sizeof(a) / sizeof(a[0]), a);

    printf("The desired output appears at level: %d\n", result);

    return 0;
}
