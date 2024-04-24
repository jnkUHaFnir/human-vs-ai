#include <stdio.h>
#include <string.h>

int main() {
    const char *path_cmp1 = "/Users/john/";
    const char *path_cmp2 = "foo/bar.txt";
    char path[100]; // Make sure the path buffer is large enough to hold the concatenated strings

    strncpy(path, path_cmp1, sizeof(path));
    strncat(path, path_cmp2, sizeof(path) - strlen(path) - 1); // -1 to account for the null terminator
    
    printf("Path: %s\n", path);

    return 0;
}
