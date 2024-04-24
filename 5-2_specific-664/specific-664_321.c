#include <stdlib.h>

// Comparison function for qsort
int compareFiles(const void *a, const void *b) {
    return ((struct file*)a)->file_info.st_size - ((struct file*)b)->file_info.st_size;
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
            files[counter].name = path;
            stat(path, &buf);
            files[counter].file_info.st_size = buf.st_size;
            printf("%s%s%ld%s\n", files[counter].name, " - ", files[counter].file_info.st_size, "bytes");
            counter++;

            listFilesRecursively(path, size);
        }
    }
    closedir(dir);

    // Sort the files array before outputting
    qsort(files, size, sizeof(struct file), compareFiles);

    // Output the sorted files
    for (int i = 0; i < size; i++) {
        printf("%s%s%ld%s\n", files[i].name, " - ", files[i].file_info.st_size, "bytes");
    }
}
