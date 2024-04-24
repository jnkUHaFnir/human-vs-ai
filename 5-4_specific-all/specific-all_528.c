#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void rmrf(char *path) {
    struct dirent *entry;
    DIR *directory;
    char full_path[1024]; // Temporary buffer to hold full path

    directory = opendir(path);
    if (directory == NULL) { // Check if directory can be opened
        perror("opendir");
        return;
    }

    while ((entry = readdir(directory)) != NULL) {
        if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, "..")) {
            continue; // Skip "." and ".."
        }

        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        if (entry->d_type == DT_DIR) { // Directory
            rmrf(full_path); // Recursively delete subdirectory
        } else { // File
            if (remove(full_path) != 0) {
                perror("remove");
            }
        }
    }

    closedir(directory);

    if (rmdir(path) != 0) {
        perror("rmdir");
    }
}

int main() {
    rmrf("Who");
    return 0;
}
