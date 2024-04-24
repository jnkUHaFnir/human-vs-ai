#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *path_cmp1 = "/Users/john/";
    char *path_cmp2 = "foo/bar.txt";
    
    size_t len1 = strlen(path_cmp1);
    size_t len2 = strlen(path_cmp2);
    
    // Allocate memory for the concatenated path
    char *path = (char *)malloc(len1 + len2 + 1); // +1 for the null terminator
    if (path == NULL) {
        perror("Error allocating memory");
        return 1;
    }
    
    // Copy the first part of the path
    strcpy(path, path_cmp1);
    
    // Concatenate the second part of the path
    strcat(path, path_cmp2);
    
    // Now path contains the concatenated path
    printf("Constructed path: %s\n", path);
    
    // Don't forget to free the dynamically allocated memory
    free(path);
    
    return 0;
}
