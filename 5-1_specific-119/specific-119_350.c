#include <stdio.h>

char path_cmp1[] = "/Users/john/";
char path_cmp2[] = "foo/bar.txt";
char path[100]; // Make sure this buffer is large enough to hold the result

int main() {
    snprintf(path, sizeof(path), "%s%s", path_cmp1, path_cmp2);

    printf("Full Path: %s\n", path);
    
    return 0;
}
