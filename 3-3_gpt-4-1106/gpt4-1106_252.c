#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    const char *path_cmp1 = "/Users/john/";
    const char *path_cmp2 = "foo/bar.txt";

    // Calculate the length of the resulting path string
    unsigned len = strlen(path_cmp1) + strlen(path_cmp2) + 1; // +1 for '\0'

    // Allocate memory for the concatenated path
    char *path = malloc(len);
    if (path == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Use snprintf to concatenate the path components safely
    snprintf(path, len, "%s%s", path_cmp1, path_cmp2);

    // Use the path
    printf("Constructed path: %s\n", path);

    // Remember to free the allocated memory when done
    free(path);

    return 0;
}
