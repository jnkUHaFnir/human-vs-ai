#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    const char *path_cmp1 = "/Users/john/";
    const char *path_cmp2 = "foo/bar.txt";
    
    // Calculate the required length of the final path
    size_t len = strlen(path_cmp1) + strlen(path_cmp2) + 1; // +1 for the null terminator

    // Dynamically allocate the memory for the path
    char *path = malloc(len);
    if (path == NULL) {
        // Handle memory allocation error
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Use snprintf to construct the path safely
    snprintf(path, len, "%s%s", path_cmp1, path_cmp2);

    // Use the path as needed
    printf("Constructed path: %s\n", path);

    // Don't forget to free the allocated memory when done
    free(path);

    return 0;
}
#include <stdio.h>
#include <string.h>

int main(void) {
    const char *path_cmp1 = "/Users/john/";
    const char *path_cmp2 = "foo/bar.txt";
    
    // Define a fixed-size buffer that you know is large enough
    char path[1024]; // Make sure the size is big enough for all your paths

    // Use snprintf to construct the path safely
    snprintf(path, sizeof(path), "%s%s", path_cmp1, path_cmp2);

    // Use the path as needed
    printf("Constructed path: %s\n", path);

    return 0;
}
