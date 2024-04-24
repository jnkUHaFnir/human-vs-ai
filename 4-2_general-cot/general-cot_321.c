#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

struct file {
    char name[1000];
    struct stat file_info;
};

int compareFileSize(const void *a, const void *b) {
    return (((struct file*)a)->file_info.st_size - ((struct file*)b)->file_info.st_size);
}

void listFilesRecursively(char *basePath, int size) {
    char path[1000];
    struct dirent *dp;
    struct file *files = malloc(size * sizeof(struct file)); // Allocate memory for files array
    DIR *dir = opendir(basePath);
    int counter = 0;
    if (!dir) return;
    
    while ((dp = readdir(dir)) != NULL) {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0) {
            strcpy(path, basePath);
            strcat(path, "/");
            strcat(path, dp->d_name);
            strcpy(files[counter].name, path);
            stat(path, &files[counter].file_info);
            counter++;
            listFilesRecursively(path, size);
        }
    }
    closedir(dir);

    qsort(files, size, sizeof(struct file), compareFileSize); // Sort the files array based on file sizes

    for (int i = 0; i < size; i++) {
        printf("%s%s%ld%s\n", files[i].name, " - ", files[i].file_info.st_size, "bytes");
    }

    free(files); // Free dynamically allocated memory
}

int main() {
    listFilesRecursively("path_to_directory", 10); // Change the directory path and size accordingly
    return 0;
}
