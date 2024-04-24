#include <stdio.h>
#include <string.h>

int main() {
    char path_cmp1[] = "/Users/john/";
    char path_cmp2[] = "foo/bar.txt";
    // Allocate enough space for the combined path
    char path[sizeof(path_cmp1) + sizeof(path_cmp2)];
    
    strcpy(path, path_cmp1);  // Copy the first path component
    
    // Concatenate the second path component
    strcat(path, path_cmp2);
    
    printf("Path: %s\n", path);
    
    return 0;
}
