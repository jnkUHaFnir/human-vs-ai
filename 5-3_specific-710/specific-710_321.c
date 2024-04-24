#include <stdlib.h> // for qsort

// Define a comparator function for qsort to sort files based on size
int compareFileSize(const void *a, const void *b) {
    const struct file *fileA = (const struct file *)a;
    const struct file *fileB = (const struct file *)b;
    return fileA->file_info.st_size - fileB->file_info.st_size;
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
            printf("%s%s%ld%s\n", files[counter].name, " - ",
                   files[counter].file_info.st_size, "bytes");
            counter++;

            listFilesRecursively(path, size);
        }
    }
    closedir(dir);

    // Sort the files array based on file size before outputting
    qsort(files, counter, sizeof(struct file), compareFileSize);

    // Output the sorted files array
    for (int i = 0; i < counter; i++) {
        printf("%s%s%ld%s\n", files[i].name, " - ", files[i].file_info.st_size, "bytes");
    }
}
