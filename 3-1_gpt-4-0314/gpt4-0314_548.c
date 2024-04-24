#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    char *directions[3];

    for (i=0; i<3; i++) {
        directions[i] = (char*) malloc(100 * sizeof(char)); // Allocating memory for each string
        if (directions[i] == NULL) {
            printf("Error allocating memory!\n");
            return 1;
        }
        scanf("%s", directions[i]);
    }
    for (i=0; i<3; i++) {
        printf("%s\n", directions[i]);
    }

    // Freeing the allocated memory
    for (i=0; i<3; i++) {
        free(directions[i]);
    }

    return 0;
}
