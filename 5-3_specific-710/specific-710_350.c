#include <stdio.h>
#include <stdlib.h>

char *path_cmp1 = "/Users/john/";
char *path_cmp2 = "foo/bar.txt";

size_t total_len = strlen(path_cmp1) + strlen(path_cmp2) + 1; // +1 for null terminator
char *path = malloc(total_len);

if (path == NULL) {
    // Handle memory allocation failure
    exit(1);
}

// Use sprintf to construct the path
sprintf(path, "%s%s", path_cmp1, path_cmp2);

// Now path contains the concatenated path
printf("Path: %s\n", path);

// Don't forget to free the allocated memory when done
free(path);
