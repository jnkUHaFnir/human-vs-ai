char path[100]; // Make sure it's large enough to hold the entire path
char *path_cmp1 = "/Users/john/";
char *path_cmp2 = "foo/bar.txt";

snprintf(path, sizeof(path), "%s%s", path_cmp1, path_cmp2);
