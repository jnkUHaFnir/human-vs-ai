#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

struct file {
    char name[1000];
    off_t size;
};

int compare_files(const void *a, const void *b) {
    struct file *file_a = (struct file *)a;
    struct file *file_b = (struct file *)b;
    return (file_a->size > file_b->size) - (file_a->size < file_b->size);
}

// ... (other necessary parts of the code)
// Define the `file` structure with necessary members
struct file {
    char name[PATH_MAX];
    off_t size;
};

// The file comparator for sorting
int compare_files(const void *a, const void *b) {
    struct file *file_a = (struct file *)a;
    struct file *file_b = (struct file *)b;
    // This will sort by size; you might want to adjust the sorting criteria
    return (file_a->size > file_b->size) - (file_a->size < file_b->size);
}

// Recursive function to list and gather file information
void listFilesRecursively(char *basePath, struct file *files, int *counter) {
    char path[PATH_MAX];
    struct dirent *dp;
    struct stat buf;
    DIR *dir = opendir(basePath);
    
    if (!dir) return;
    
    while ((dp = readdir(dir)) != NULL) {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0) {
            snprintf(path, sizeof(path), "%s/%s", basePath, dp->d_name);
            stat(path, &buf);
            if (S_ISREG(buf.st_mode)) {  // Check if it's a regular file
                strncpy(files[*counter].name, path, sizeof(files[*counter].name));
                files[*counter].size = buf.st_size;
                (*counter)++;
            }
            // Continue recursion if it's a directory
            if (S_ISDIR(buf.st_mode)) {
                listFilesRecursively(path, files, counter);
            }
        }
    }
    closedir(dir);
}

// Utility function to invoke the recursive function and print sorted results
void findAndSortFiles(char *basePath, int maxFiles) {
    struct file *files = malloc(sizeof(struct file) * maxFiles);
    if (!files) {
        printf("Memory allocation error\n");
        return;
    }
    int counter = 0;
    listFilesRecursively(basePath, files, &counter);

    qsort(files, counter, sizeof(struct file), compare_files);

    // Print sorted files
    for (int i = 0; i < counter; i++) {
        printf("%s - %ld bytes\n", files[i].name, files[i].size);
    }

    // Clean up
    free(files);
}

int main() {
    // Define the maxFiles value
    int maxFiles = 1000; // Adjust this as necessary
    findAndSortFiles("/path/to/directory", maxFiles);
    return 0;
}
