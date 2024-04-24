char *path_cmp1 = "/Users/john/";
char *path_cmp2 = "foo/bar.txt";

char *path = malloc(strlen(path_cmp1) + strlen(path_cmp2) + 1);
strcpy(path, path_cmp1);
strcat(path, path_cmp2);

// Now path contains the concatenated path
// ... use it as needed ...

free(path); // Don't forget to free the memory when you're done with it
char *path_cmp1 = "/Users/john/";
char *path_cmp2 = "foo/bar.txt";

char path[strlen(path_cmp1) + strlen(path_cmp2) + 1];
sprintf(path, "%s%s", path_cmp1, path_cmp2);

// Now path contains the concatenated path
// ... use it as needed ...
