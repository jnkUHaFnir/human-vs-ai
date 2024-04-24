#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char path_cmp1[] = "/Users/john/";
    char path_cmp2[] = "foo/bar.txt";
    
    // Calculate the total length needed for the concatenated path
    size_t total_len = strlen(path_cmp1) + strlen(path_cmp2) + 1; // +1 for null terminator
    
    // Allocate memory for the concatenated path
    char *path = (char *)malloc(total_len);
    
    if (path == NULL) {
        // Handle memory allocation failure
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    
    // Concatenate the paths using sprintf
    sprintf(path, "%s%s", path_cmp1, path_cmp2);
    
    // Use the concatenated path
    
    // Don't forget to free the memory when you're done
    free(path);
    
    return 0;
}
