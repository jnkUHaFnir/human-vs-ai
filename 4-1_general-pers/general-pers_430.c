#include <stdio.h>
#include <stdlib.h>

int main() {
    // Dimensions of the 3D array
    int sz[3] = {2, 3, 4};

    // Allocate memory for the 3D array
    int (*a)[sz[1]][sz[2]] = calloc(sz[0], sizeof(*a));
    if (a == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    // Access and modify elements of the 3D array
    for (int i = 0; i < sz[0]; i++) {
        for (int j = 0; j < sz[1]; j++) {
            for (int k = 0; k < sz[2]; k++) {
                (*a)[i][j][k] = i + j + k;
                printf("%d ", (*a)[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    // Free the allocated memory
    free(a);

    return 0;
}
