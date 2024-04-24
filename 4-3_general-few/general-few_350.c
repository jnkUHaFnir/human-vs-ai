#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *path_cmp1 = "/Users/john/";
    char *path_cmp2 = "foo/bar.txt";
  
    // Calculate the total length needed for the concatenated string
    size_t total_len = strlen(path_cmp1) + strlen(path_cmp2) + 1; // +1 for the NULL terminator

    // Allocate memory for the concatenated path
    char *path = (char *)malloc(total_len);
  
    // Check if memory allocation was successful
    if (path == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }
  
    // Copy the first path component
    strcpy(path, path_cmp1);
    // Concatenate the second path component
    strcat(path, path_cmp2);
  
    // Use the concatenated path as needed
  
    printf("Concatenated path: %s\n", path);

    // Don't forget to free the dynamically allocated memory
    free(path);

    return 0;
}
