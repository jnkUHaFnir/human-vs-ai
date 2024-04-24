#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

int rmrf(char *path) {
    DIR *directory = opendir(path);
    if (directory == NULL) {
        return -1; // Error opening directory
    }

    struct dirent *entry = readdir(directory);
    while (entry != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char entry_path[1024];
            snprintf(entry_path, sizeof(entry_path), "%s/%s", path, entry->d_name);

            struct stat statbuf;
            if (lstat(entry_path, &statbuf) == 0) {
                if (S_ISDIR(statbuf.st_mode)) {
                    rmrf(entry_path); // Recursively delete subdirectories
                } else {
                    remove(entry_path); // Delete file
                }
            }
        }
        entry = readdir(directory);
    }

    closedir(directory);

    rmdir(path); // Remove the directory itself

    return 0;
}
