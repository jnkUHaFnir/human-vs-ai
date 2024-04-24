#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    char **t;
    t = (char **)malloc(100 * sizeof(char *));

    for (i = 0; i < 100; i++) {
        t[i] = (char *)malloc(16 * sizeof(char));
    }

    // Do some operations with t

    // Free the allocated memory
    for (i = 0; i < 100; i++) {
        free(t[i]);
    }
    free(t);

    return 0;
}
