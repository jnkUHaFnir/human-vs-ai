#include <stdio.h>
#include <libgen.h>
#include <limits.h>
#include <unistd.h>

int main() {
    char path[PATH_MAX];
    char file[] = "file.txt";
    ssize_t len = readlink("/proc/self/exe", path, sizeof(path) - 1);
    if (len != -1) {
        path[len] = '\0';
        char *dir_path = dirname(path);
        char full_path[PATH_MAX];
        snprintf(full_path, PATH_MAX, "%s/%s", dir_path, file);
        printf("Full path: %s\n", full_path);
        // Now you can use full_path with open()
    } else {
        perror("readlink");
        return 1;
    }
    
    return 0;
}
