#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *path_cmp1 = "/Users/john/";
    char *path_cmp2 = "foo/bar.txt";

    // Allocate memory for the final path
    char *path = (char *)malloc(strlen(path_cmp1) + strlen(path_cmp2) + 1);

    // Check if memory allocation was successful
    if (path == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Copy the first path component to the final path
    strcpy(path, path_cmp1);

    // Concatenate the second path component to the final path
    strcat(path, path_cmp2);

    // Print the final path
    printf("Final path: %s\n", path);

    // Free dynamically allocated memory
    free(path);

    return 0;
}
