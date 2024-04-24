#include <stdio.h>
#include <stdlib.h>

int main() {
    int sz[3] = {2, 3, 4};

    // Allocate memory for a 3D array
    int (*a)[sz[1]][sz[2]] = calloc(sz[0], sizeof(*a));

    // Assign values to the 3D array
    for (int i = 0; i < sz[0]; i++) {
        for (int j = 0; j < sz[1]; j++) {
            for (int k = 0; k < sz[2]; k++) {
                a[i][j][k] = i * 100 + j * 10 + k;
            }
        }
    }

    // Access and print values
    for (int i = 0; i < sz[0]; i++) {
        for (int j = 0; j < sz[1]; j++) {
            for (int k = 0; k < sz[2]; k++) {
                printf("a[%d][%d][%d] = %d\n", i, j, k, a[i][j][k]);
            }
        }
    }

    // Free the memory allocated for the 3D array
    free(a);

    return 0;
}
