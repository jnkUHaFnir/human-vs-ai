#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int rmrf(char *path) {
    DIR *directory = opendir(path);
    if (directory == NULL) {
        return -1; // Error opening directory
    }

    struct dirent *entry;
    while ((entry = readdir(directory)) != NULL) {
        if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, "..")) {
            continue; // Skip current and parent directory
        }

        char *path_copy = malloc(strlen(path) + strlen(entry->d_name) + 2);
        strcpy(path_copy, path);
        strcat(path_copy, "/");
        strcat(path_copy, entry->d_name);

        if (entry->d_type == DT_DIR) {
            rmrf(path_copy); // Recursively remove subdirectory
            remove(path_copy); // Remove empty directory
        } else {
            remove(path_copy); // Remove file
        }

        free(path_copy); // Free memory allocated for path_copy
    }

    closedir(directory);
    return 0;
}

int main() {
    rmrf("Path_to_your_directory_to_delete");
    return 0;
}
