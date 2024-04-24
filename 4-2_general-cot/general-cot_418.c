#include <stdio.h>
#include <stdlib.h>

int main() {
    int sz[3] = {2, 3, 4};

    int (*a)[sz[1]][sz[2]] = calloc(sz[0], sizeof(*a));

    // Assign values to the 3D array
    for (int i = 0; i < sz[0]; i++) {
        for (int j = 0; j < sz[1]; j++) {
            for (int k = 0; k < sz[2]; k++) {
                a[i][j][k] = i * sz[1] * sz[2] + j * sz[2] + k;
            }
        }
    }

    // Access and print values from the 3D array
    for (int i = 0; i < sz[0]; i++) {
        for (int j = 0; j < sz[1]; j++) {
            for (int k = 0; k < sz[2]; k++) {
                printf("%d ", a[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    free(a);

    return 0;
}
