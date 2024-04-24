#include <stdio.h>
#include <string.h>

int main() {
    char path_cmp1[] = "/Users/john/";
    char *path_cmp2 = "foo/bar.txt";
    
    char path[100]; // Allocate enough memory for the concatenated path

    strcpy(path, path_cmp1); // Copy the first path component

    strcat(path, path_cmp2); // Concatenate the second path component

    printf("Full path: %s\n", path);

    return 0;
}
