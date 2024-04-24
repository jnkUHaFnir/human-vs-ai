#include <stdio.h>
#include <string.h>

int main() {
    char path_cmp1[] = "/Users/john/";
    char path_cmp2[] = "foo/bar.txt";
    char path[100]; // Make sure to allocate enough space

    strcpy(path, path_cmp1);
    strcat(path, path_cmp2);

    printf("The concatenated path is: %s\n", path);

    return 0;
}
