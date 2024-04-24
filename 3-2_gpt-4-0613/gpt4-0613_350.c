#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *path_comp1 = "/Users/john/";
    const char *path_comp2 = "foo/bar.txt";
    char *path;

    // Calculate the length required for the final string
    int len = snprintf(NULL, 0, "%s%s", path_comp1, path_comp2);
    // Allocate memory for the final string
    path = malloc(len + 1);

    if (path == NULL) {
        // handle malloc failure
        fprintf(stderr, "malloc failed\n");
        return EXIT_FAILURE;
    }

    // Construct the final string
    sprintf(path, "%s%s", path_comp1, path_comp2);

    printf("%s\n", path);

    // Free allocated memory
    free(path);

    return EXIT_SUCCESS;
}
