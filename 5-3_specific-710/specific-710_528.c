#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

void rmrf(char *path) {
    DIR *directory = opendir(path);
    if (directory == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    struct dirent *entry;
    while ((entry = readdir(directory)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; // Skip "." and ".."
        }

        size_t path_len = strlen(path);
        size_t entry_len = strlen(entry->d_name);
        char *new_path = malloc(path_len + 1 + entry_len + 1); // +1 for separator, +1 for null terminator
        if (new_path == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }

        strcpy(new_path, path);
        strcat(new_path, "/");
        strcat(new_path, entry->d_name);

        if (entry->d_type == DT_DIR) {
            rmrf(new_path); // Recursively visit directories
            rmdir(new_path); // Remove directory after its contents are deleted
        } else {
            remove(new_path); // Delete file
        }

        free(new_path);
    }

    closedir(directory);
}

int main() {
    rmrf("Who");
    return 0;
}
