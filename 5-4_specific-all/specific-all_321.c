#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

struct file {
    char *name;
    struct stat file_info;
};

void bubbleSort(struct file *arr, int size) {
    int i, j;
    struct file temp;

    for(i = 0; i < size-1; i++) {
        for(j = 0; j < size-i-1; j++) {
            if(strcmp(arr[j].name, arr[j+1].name) > 0) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
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
            files[counter].name = strdup(path); // Allocate memory for the path
            stat(path, &buf);
            files[counter].file_info.st_size = buf.st_size;
            printf("%s%s%ld%s\n", files[counter].name, " - ",
                   files[counter].file_info.st_size, "bytes");
            counter++;

            listFilesRecursively(path, size);
        }
    }
    closedir(dir);

    bubbleSort(files, size);

    // Output the sorted files array
    for (int i = 0; i < size; ++i) {
        printf("%s%s%ld%s\n", files[i].name, " - ",
               files[i].file_info.st_size, "bytes");
        free(files[i].name); // Free the dynamically allocated memory
    }
}

int main() {
    listFilesRecursively(".", 10); // Example usage with size 10
    return 0;
}
