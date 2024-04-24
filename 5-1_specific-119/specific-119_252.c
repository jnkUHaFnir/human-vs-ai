#include <stdio.h>

int main() {
    char path_cmp1[] = "/Users/john/";
    char path_cmp2[] = "foo/bar.txt";
    char path[100];  // Make sure to adjust the size according to your needs

    // Construct the file path safely
    snprintf(path, sizeof(path), "%s%s", path_cmp1, path_cmp2);

    printf("File path: %s\n", path);

    return 0;
}
