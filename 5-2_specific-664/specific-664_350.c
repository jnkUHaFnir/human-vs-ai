#include <stdio.h>
#include <string.h>

int main() {
    char path_cmp1[] = "/Users/john/";
    char path_cmp2[] = "foo/bar.txt";
    char path[100]; // Allocate a buffer with enough space

    snprintf(path, sizeof(path), "%s%s", path_cmp1, path_cmp2);

    printf("Constructed path: %s\n", path);

    return 0;
}
