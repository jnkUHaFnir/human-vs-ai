#include <stdio.h>
#include <stdlib.h>

int **DoThis(int n, int arr[n]){
    int l = n;
    int **b = malloc(l * sizeof(*b));
    int i, j, k;
    for (i = 0; i < l; i++) {
        j = (i + 1) % l;
        int *copy = malloc(l * sizeof(*copy));
        for (k = 0; k < l; k++)
            copy[k] = arr[k];
        int t = copy[i];
        copy[i] = copy[j];
        copy[j] = t;
        b[i] = copy;
    }
    return b;
}

int main() {
    int a[] = {2,3,4,1};
    int b[] = {1,2,4,3};
    int target[] = {1,2,4,3};
    int **result = NULL;
    
    int level = 1;
    int l = sizeof(a) / sizeof(a[0]);
    
    do {
        result = DoThis(l, a);
        for (int i = 0; i < l; i++) {
            int match = 1;
            for (int j = 0; j < l; j++) {
                if (result[i][j] != target[j]) {
                    match = 0;
                    break;
                }
            }
            if (match) {
                printf("Output found at level %d\n", level);
                break;
            }
        }
        // Free memory allocated for result
        for (int i = 0; i < l; i++) {
            free(result[i]);
        }
        free(result);
        
        level++;
        a = target; // Update input for next iteration
    } while (level < 100); // You can set a maximum limit for levels
    
    return 0;
}
