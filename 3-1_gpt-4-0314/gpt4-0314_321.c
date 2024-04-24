#include <stdlib.h> // needed for qsort

int compare(const void *a, const void *b) {
    const struct file *file_a = (const struct file *)a;
    const struct file *file_b = (const struct file *)b;
    
    if (file_a->file_info.st_size < file_b->file_info.st_size) return -1;
    if (file_a->file_info.st_size > file_b->file_info.st_size) return 1;
    return 0;
}
    qsort(files, counter, sizeof(struct file), compare);

    for (int i = 0; i < counter; i++) {
        printf("%s%s%ld%s\n", files[i].name, " - ", files[i].file_info.st_size, "bytes");
    }
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

struct file {
    char *name;
    struct stat file_info;
};

int compare(const void *a, const void *b) {
    const struct file *file_a = (const struct file *)a;
    const struct file *file_b = (const struct file *)b;

    if (file_a->file_info.st_size < file_b->file_info.st_size) return -1;
    if (file_a->file_info.st_size > file_b->file_info.st_size) return 1;
    return 0;
}

void listFilesRecursively(char *basePath, int size) {
    char path[1000];
    struct dirent *dp;
    struct file files[size];
    struct stat buf;
    DIR *dir = opendir(basePath);
    int counter = 0;
    if (!dir) return;
    while ((dp = readdir(dir)) != NULL) {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0) {
            strcpy(path, basePath);
            strcat(path, "/");
            strcat(path, dp->d_name);
            files[counter].name = strdup(path); // Use strdup to avoid overwriting the same memory address
            stat(path, &buf);
            files[counter].file_info.st_size = buf.st_size;
            counter++;

            listFilesRecursively(path, size);
        }
    }
    closedir(dir);

    qsort(files, counter, sizeof(struct file), compare);

    for (int i = 0; i < counter; i++) {
        printf("%s%s%ld%s\n", files[i].name, " - ", files[i].file_info.st_size, "bytes");
        free(files[i].name); // Free the allocated memory used by strdup
    }
}
