#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int rmrf(const char *path) {
    DIR *directory = opendir(path);
    if (directory == NULL) {
        return -1; // Error opening directory
    }
    
    struct dirent *entry;
    char entry_path[1024];

    while ((entry = readdir(directory)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; // Skip "." and ".."
        }

        snprintf(entry_path, sizeof(entry_path), "%s/%s", path, entry->d_name);

        if (entry->d_type == DT_DIR) {
            rmrf(entry_path); // Recursively delete subdirectory
        } else {
            remove(entry_path); // Delete file
        }
    }

    closedir(directory);

    // Remove the directory itself after deleting its contents
    rmdir(path); 

    return 0;
}

int main() {
    rmrf("path/to/directory");
    return 0;
}
