#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int rmrf(char *path) {
    // Allocate a buffer for constructing paths.
    char path_copy[1024];
    DIR *directory = opendir(path);
    if (!directory) {
        return -1;
    }
    struct dirent *entry;
    while ((entry = readdir(directory)) != NULL) {
        if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, "..")) {
            continue;
        }

        // Construct new path from base path and entry name
        snprintf(path_copy, sizeof(path_copy), "%s/%s", path, entry->d_name);

        if (entry->d_type == DT_DIR) {
            // If it's a directory, recursively delete its contents
            if (rmrf(path_copy) == -1) { // On failure, stop and report back
                closedir(directory);
                return -1;
            }
        } else {
            // If it's a file, delete it
            if (remove(path_copy) == -1) { // On failure, stop and report back
                closedir(directory);
                return -1;
            }
        }
    }
    closedir(directory);

    // Finally, delete the now empty directory itself
    return remove(path);
}

int main() {
    // Test the function (be very careful with the path you use for testing!)
    int result = rmrf("/path/to/your/test/directory");
    if (result == 0) {
        printf("Directory deleted successfully\n");
    } else {
        perror("Failed to delete directory");
    }

    return result;
}
