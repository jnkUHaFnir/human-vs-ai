#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

int rmrf(char *path) {
    char* path_copy = malloc(1024);
    if (path_copy == NULL) {
        perror("Malloc failed");
        return -1;
    }

    DIR *directory = opendir(path);
    if (directory == NULL) {
        perror("Error opening directory");
        free(path_copy);
        return -1;
    }

    struct dirent *entry = readdir(directory);
    while (entry != NULL) {
        if (strcmp(entry->d_name, ".") && strcmp(entry->d_name, "..")) {
            strcpy(path_copy, path);
            strcat(path_copy, "/");
            strcat(path_copy, entry->d_name);

            struct stat stat_buffer;
            if (stat(path_copy, &stat_buffer) == 0) {
                if (S_ISDIR(stat_buffer.st_mode)) {
                    rmrf(path_copy);
                } else {
                    remove(path_copy);
                }
            }
        }

        entry = readdir(directory);
    }

    closedir(directory);
    free(path_copy);
    return 0;
}

int main() {
    rmrf("example_directory"); // Change to the desired directory path
    return 0;
}
