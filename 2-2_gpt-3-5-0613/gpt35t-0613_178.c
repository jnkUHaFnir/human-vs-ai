#include <stdio.h>
#include <stdlib.h>

int **DoThis(int n, int arr[n], int level){
    int l = n;
    int **b = malloc(l * sizeof(*b));//sizeof(*b) : sizeof(int *)
    int i, j, k;
    for (i = 0; i < l; i++) {
        j = (i + 1) % l;
        int *copy = malloc(l * sizeof(*copy));//sizeof(int)
        for (k = 0; k < l; k++)
            copy[k] = arr[k];
        int t = copy[i];
        copy[i] = copy[j];
        copy[j] = t;
        if (level == 1) {
            printf("%d,", copy[0]);     // Print the first element
            for (k = 1; k < l - 1; k++) {
                printf("%d,", copy[k]); // Print the middle elements
            }
            printf("%d\n", copy[l - 1]); // Print the last element
        } else {
            b[i] = DoThis(n, copy, level - 1); // Make recursive call with updated array and reduced level
        }
    }
    return b;
}

int main() {
    int a[] = {2, 3, 4, 1};
    int n = sizeof(a) / sizeof(a[0]);
    int level = 2; // The desired level at which we want to stop
    
    DoThis(n, a, level);
    return 0;
}
3,2,4,1
2,4,3,1
2,3,1,4
1,3,4,2
2
