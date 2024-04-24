#include <stdio.h>
#include <string.h>

int main() {
    char path_cmp1[] = "/Users/john/";
    char path_cmp2[] = "foo/bar.txt";
    char path[50]; // Make sure path has enough space for the combined string

    sprintf(path, "%s%s", path_cmp1, path_cmp2);
    
    printf("Constructed path: %s\n", path);

    return 0;
}
#include <stdio.h>
#include <string.h>

int main() {
    char path_cmp1[] = "/Users/john/";
    char path_cmp2[] = "foo/bar.txt";
    char path[50]; // Make sure path has enough space for the combined string

    strcpy(path, path_cmp1); // Copy the first part of the path

    strcat(path, path_cmp2); // Concatenate the second part of the path

    printf("Constructed path: %s\n", path);

    return 0;
}
