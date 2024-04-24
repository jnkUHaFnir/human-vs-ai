#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *path_cmp1 = "/Users/john/";
    char *path_cmp2 = "foo/bar.txt";

    // +1 for possible path separator, +1 for null terminator
    size_t total_length = strlen(path_cmp1) + strlen(path_cmp2) + 2;
    
    // Allocate enough memory to hold the full path
    char *path = malloc(total_length);
    if (path == NULL) {
        // Handle memory allocation failure
        fprintf(stderr, "Error allocating memory\n");
        exit(1);
    }
    
    // Copy first component into path
    strcpy(path, path_cmp1);
    
    // Append a path separator if needed (simple example, not platform-aware)
    if (path_cmp1[strlen(path_cmp1) - 1] != '/') {
        strcat(path, "/");
    }
    
    // Append second path component
    strcat(path, path_cmp2);
    
    // Use the path...
    printf("Full path: %s\n", path);
    
    // Remember to free the allocated memory
    free(path);
    
    return 0;
}
