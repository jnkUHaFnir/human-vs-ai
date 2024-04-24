#include <stdio.h>
#include <string.h>

int main() {
    char path_cmp1[] = "/Users/john/";
    char path_cmp2[] = "foo/bar.txt";
    char path[100]; // Make sure this buffer is large enough to hold the concatenated string

    strcpy(path, path_cmp1); // Copy path_cmp1 to path
    strcat(path, path_cmp2); // Concatenate path_cmp2 to path

    printf("The constructed path is: %s\n", path);

    return 0;
}
