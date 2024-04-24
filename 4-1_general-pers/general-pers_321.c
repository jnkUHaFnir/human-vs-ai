#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

struct file {
    char name[1000];
    struct stat file_info;
};

void listFilesRecursively(char *basePath) {
    char path[1000];
    struct dirent *dp;
    struct file *files = NULL;
    DIR *dir = opendir(basePath);
    int counter = 0;

    if (!dir) return;

    while ((dp = readdir(dir)) != NULL) {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0) {
            strcpy(path, basePath);
            strcat(path, "/");
            strcat(path, dp->d_name);

            struct stat buf;
            stat(path, &buf);

            if (counter == 0) {
                files = malloc(sizeof(struct file));
            } else {
                files = realloc(files, (counter + 1) * sizeof(struct file));
            }

            if (files == NULL) {
                // Error handling - unable to allocate memory
                return;
            }

            strcpy(files[counter].name, path);
            files[counter].file_info.st_size = buf.st_size;
            counter++;

            listFilesRecursively(path);
        }
    }

    closedir(dir);

    // Sorting the files array in ascending order based on file size
    qsort(files, counter, sizeof(struct file), compare);

    // Output the sorted files
    for (int i = 0; i < counter; i++) {
        printf("%s - %ld bytes\n", files[i].name, files[i].file_info.st_size);
    }

    // Free dynamically allocated memory
    free(files);
}

int compare(const void *a, const void *b) {
    const struct file *fileA = (const struct file *)a;
    const struct file *fileB = (const struct file *)b;

    return (fileA->file_info.st_size - fileB->file_info.st_size);
}
