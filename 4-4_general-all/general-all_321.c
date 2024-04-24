#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

// Define a structure to hold file information
struct file {
    char name[1000];
    struct stat file_info;
};

void listFilesRecursively(char *basePath, int size);

int compareFileSize(const void *a, const void *b) {
    struct file *fileA = (struct file*)a;
    struct file *fileB = (struct file*)b;
    return (int)(fileA->file_info.st_size - fileB->file_info.st_size);
}

void listFilesRecursively(char *basePath, int size) {
    char path[1000];
    struct dirent *dp;
    struct file files[size];
    DIR *dir = opendir(basePath);
    int counter = 0;
    if (!dir) return;
    
    while ((dp = readdir(dir)) != NULL) {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0) {
            strcpy(path, basePath);
            strcat(path, "/");
            strcat(path, dp->d_name);
            
            // Populate the file structure
            strcpy(files[counter].name, path);
            stat(path, &files[counter].file_info);

            counter++;

            listFilesRecursively(path, size);
        }
    }
    closedir(dir);

    // Sort the files array based on file size
    qsort(files, size, sizeof(struct file), compareFileSize);

    // Output the sorted files
    for (int i = 0; i < size; i++) {
        printf("%s%s%ld%s\n", files[i].name, " - ", files[i].file_info.st_size, " bytes");
    }
}

int main() {
    listFilesRecursively(".", 10); // Example usage
    return 0;
}
