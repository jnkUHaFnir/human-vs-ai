#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

struct file {
    char *name; // Dynamically allocated
    off_t size; // For file size
};

// Function prototype
void listFilesRecursively(char *basePath);

int compareFiles(const void *a, const void *b) {
    struct file *fileA = (struct file *)a;
    struct file *fileB = (struct file *)b;
    return (fileA->size - fileB->size);
}

void listFilesRecursively(char *basePath) {
    char path[1000];
    struct dirent *dp;
    DIR *dir = opendir(basePath);

    if (!dir) return;

    // Initial allocation assuming some max count, reallocate as needed
    int maxFiles = 10;
    struct file *files = malloc(sizeof(struct file) * maxFiles);
    int counter = 0;

    while ((dp = readdir(dir)) != NULL) {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0) {
            snprintf(path, sizeof(path), "%s/%s", basePath, dp->d_name);
            struct stat buf;
            if (stat(path, &buf) < 0)
                continue;
            
            if (counter >= maxFiles) {
                maxFiles *= 2; // Double the size
                files = realloc(files, sizeof(struct file) * maxFiles);
            }
            
            files[counter].name = strdup(path);
            files[counter].size = buf.st_size;
            counter++;

            // Recursion moved, see below
        }
    }

    // Now sort the array
    qsort(files, counter, sizeof(struct file), compareFiles);

    // Output the sorted files
    for (int i = 0; i < counter; ++i) {
        printf("%s - %ld bytes\n", files[i].name, files[i].size);
        free(files[i].name); // Don't forget to free the memory
    }

    // Recursing over subdirectories, now that the current directory has been processed:
    for (int i = 0; i < counter; ++i) {
        // If it's a directory, recurse
        struct stat buf;
        if (stat(files[i].name, &buf) == 0 && S_ISDIR(buf.st_mode)) {
            listFilesRecursively(files[i].name);
        }
    }

    // Cleanup
    free(files);
    closedir(dir);
}

int main() {
    char basePath[] = "/your/directory/path";
    listFilesRecursively(basePath);
    return 0;
}
