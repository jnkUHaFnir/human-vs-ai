#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // components of the path
    char *path_cmp1 = "/Users/john/";
    char *path_cmp2 = "foo/bar.txt";
    
    // calculate the length of the final path
    unsigned len = strlen(path_cmp1) + strlen(path_cmp2) + 1;  // +1 for the null-terminator
    
    // allocate memory for the final path
    char *path = (char *) malloc(len);
    
    // check if memory allocation was successful
    if (path == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // safely construct the final path using snprintf()
    snprintf(path, len, "%s%s", path_cmp1, path_cmp2);

    // print the final path
    printf("Path: %s\n", path);

    // free the allocated memory
    free(path);

    return 0;
}
