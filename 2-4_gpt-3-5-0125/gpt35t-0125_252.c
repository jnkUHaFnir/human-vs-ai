#include <stdio.h>
#include <string.h>

int main() {
    // Two strings representing the path components
    char path_cmp1[] = "/Users/john/";
    char path_cmp2[] = "foo/bar.txt";

    // Allocate enough space for the combined path
    char path[strlen(path_cmp1) + strlen(path_cmp2) + 1]; // +1 for the null terminator
    
    // Copy the first path component to the new path
    strcpy(path, path_cmp1);
    
    // Concatenate the second path component to the new path
    strcat(path, path_cmp2);

    printf("Full path: %s\n", path);

    return 0;
}
