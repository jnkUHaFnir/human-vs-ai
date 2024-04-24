#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *path_cmp1 = "/Users/john/";
    char *path_cmp2 = "foo/bar.txt";
    
    // Calculate the total length needed: sum of both strings lengths plus the null terminator.
    unsigned len = strlen(path_cmp1) + strlen(path_cmp2) + 1; // +1 for the null terminator
    
    // Allocate memory to hold the concatenated path.
    char *path = malloc(len);
    
    if (path == NULL) {
        fprintf(stderr, "Failed to allocate memory.\n");
        return 1;
    }
    
    // Copy the first component to the allocated memory.
    strcpy(path, path_cmp1);
    
    // Concatenate the second component to the allocated memory.
    strcat(path, path_cmp2);
    
    // Use the path as needed.
    printf("Full path: %s\n", path);
    
    // Free the allocated memory when done.
    free(path);
    
    return 0;
}
