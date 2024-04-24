#include <stdio.h>
#include <stdlib.h>

typedef struct FileHandle {
    FILE *fp;
} FileHandle;

FileHandle *file_handle_open(const char *path, const char *mode) {
    FileHandle *fh = (FileHandle *) malloc(sizeof(FileHandle));
    fh->fp = fopen(path, mode);
    if (!fh->fp) {
        free(fh);
        return NULL;
    }
    return fh;
}

void file_handle_close(FileHandle *fh) {
    if (fh) {
        if (fh->fp) {
            fclose(fh->fp);
        }
        free(fh);
    }
}

int do_something_with_file() {
    FileHandle *fh = file_handle_open("test.txt", "r");
    if (!fh) {
        perror("File error occurred!");
        return EXIT_FAILURE;
    }

    if (other_condition) {
        perror("Other error occurred!");
        file_handle_close(fh);
        return EXIT_FAILURE;
    }

    // Do something with the file here
    // ...

    // Close the file handle
    file_handle_close(fh);
    return EXIT_SUCCESS;
}
