#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

int rmrf(char *path) {
    char path_copy[1024]; // Using fixed buffer size instead of dynamic allocation
    DIR *directory = opendir(path);
    if (directory == NULL) {
        return -1;
    }
    
    struct dirent *entry = readdir(directory);
    while (entry != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            strcpy(path_copy, path);
            strcat(path_copy, "/");
            strcat(path_copy, entry->d_name);

            struct stat statbuf;
            if (lstat(path_copy, &statbuf) == -1) {
                perror("lstat");
                closedir(directory);
                return -1;
            }

            if (S_ISDIR(statbuf.st_mode)) {
                rmrf(path_copy);
            } else {
                if (remove(path_copy) != 0) {
                    perror("remove");
                    closedir(directory);
                    return -1;
                }
            }
        }
        entry = readdir(directory);
    }
    
    closedir(directory);
    if (remove(path) != 0) {
        perror("remove");
        return -1;
    }
    
    return 0;
}

int main() {
    rmrf("path/to/directory");
    return 0;
}
