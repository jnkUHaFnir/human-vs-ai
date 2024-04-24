#include <stdio.h>

char *path_cmp1 = "/Users/john/";
char *path_cmp2 = "foo/bar.txt";
char path[1024]; // Allocate enough space for the concatenated path

snprintf(path, sizeof(path), "%s%s", path_cmp1, path_cmp2);

printf("Constructed path: %s\n", path);
