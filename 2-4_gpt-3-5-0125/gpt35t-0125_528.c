#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int rmrf(char *path) {
    DIR *directory = opendir(path);
    if (directory == NULL) {
        perror("opendir");
        return -1;
    }

    struct dirent *entry;
    while ((entry = readdir(directory)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char path_copy[1024];
        snprintf(path_copy, sizeof(path_copy), "%s/%s", path, entry->d_name);

        if (entry->d_type == DT_DIR) { 
            rmrf(path_copy);
        } else {
            if (remove(path_copy) != 0) {
                perror("remove");
                return -1;
            }
        }
    }

    closedir(directory);

    if (remove(path) != 0) {
        perror("remove");
        return -1;
    }

    return 0;
}

int main() {
    rmrf("path_to_directory");
    return 0;
}
