#include <stdio.h>
#include <string.h>

int main() {
    char path_cmp1[] = "/Users/john/";
    char path_cmp2[] = "foo/bar.txt";
    
    // Allocate enough space to hold the concatenated path
    char path[1000];
    
    // Copy the first component of the path to the destination
    strcpy(path, path_cmp1);
    
    // Concatenate the second component to the destination
    strcat(path, path_cmp2);
    
    // Print the resulting path
    printf("Path: %s\n", path);
    
    return 0;
}
