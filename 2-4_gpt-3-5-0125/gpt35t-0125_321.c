#include <stdlib.h>

int compare(const void *a, const void *b) {
    struct file *file1 = (struct file *)a;
    struct file *file2 = (struct file *)b;
    
    return file1->file_info.st_size - file2->file_info.st_size;
}

void listFilesRecursively(char *basePath, int size) {
    // existing code
    
    // Sort the array of files
    qsort(files, size, sizeof(struct file), compare);
    
    // Output the sorted files
    for (int i = 0; i < size; i++) {
        printf("%s%s%ld%s\n", files[i].name, " - ", files[i].file_info.st_size, "bytes");
    }
    
    // existing code
}
