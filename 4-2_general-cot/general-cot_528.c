#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int rmrf(char *path) {
    DIR *directory = opendir(path);
    struct dirent *entry;

    if (directory == NULL) {
        perror("opendir");
        return -1;
    }

    while ((entry = readdir(directory)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char sub_path[1024];
        snprintf(sub_path, sizeof(sub_path), "%s/%s", path, entry->d_name);

        if (entry->d_type == DT_DIR) {
            rmrf(sub_path);
        } else {
            if (remove(sub_path) != 0) {
                perror("remove");
            }
        }
    }

    closedir(directory);

    if (rmdir(path) != 0) {
        perror("rmdir");
        return -1;
    }

    return 0;
}

int main() {
    if (rmrf("Who") != 0) {
        fprintf(stderr, "Failed to delete directory\n");
    } else {
        printf("Directory deleted successfully\n");
    }
    return 0;
}
