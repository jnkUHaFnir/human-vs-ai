#include <stdlib.h>

// Comparison function for qsort
int compareFileSizes(const void *a, const void *b) {
    return ((struct file*)a)->file_info.st_size - ((struct file*)b)->file_info.st_size;
}

void listFilesRecursively(char *basePath, int size) {
    // Your existing code

    // Sort the 'files' array based on file sizes
    qsort(files, counter, sizeof(struct file), compareFileSizes);

    // Output the sorted file information
    for (int i = 0; i < counter; i++) {
        printf("%s%s%ld%s\n", files[i].name, " - ",
               files[i].file_info.st_size, "bytes");
    }

    // Your existing code
}
