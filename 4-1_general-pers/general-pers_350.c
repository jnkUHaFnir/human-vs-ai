#include <stdio.h>
#include <string.h>

int main() {
    char *path_cmp1 = "/Users/john/";
    char *path_cmp2 = "foo/bar.txt";
    unsigned len = strlen(path_cmp1);
    
    char path[PATH_MAX]; // where PATH_MAX is defined in limits.h to ensure enough space
    int ret = strcpy_s(path, sizeof(path), path_cmp1);
    if (ret != 0) {
        printf("Error copying path_cmp1.\n");
        return 1;
    }
    
    ret = strcat_s(path, sizeof(path), path_cmp2);
    if (ret != 0) {
        printf("Error concatenating path_cmp2.\n");
        return 1;
    }
    
    printf("Full path: %s\n", path);
    
    return 0;
}
