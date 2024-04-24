#include <stdio.h>

char *path_cmp1 = "/Users/john/";
char *path_cmp2 = "foo/bar.txt";
char path[256]; // Make sure this is large enough to accommodate the result

// Construct the path using snprintf
snprintf(path, sizeof(path), "%s%s", path_cmp1, path_cmp2);

printf("Constructed path: %s\n", path);
