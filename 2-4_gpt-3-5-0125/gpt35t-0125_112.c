typedef struct File {
    FILE *fp;
} File;

File* open_file(const char *filename, const char *mode) {
    File *file = malloc(sizeof(File));
    if (!file) {
        return NULL; // Handle memory allocation failure
    }

    file->fp = fopen(filename, mode);
    if (!file->fp) {
        free(file);
        return NULL; // Handle file open failure
    }

    return file;
}

void close_file(File *file) {
    if (file) {
        fclose(file->fp);
        free(file);
    }
}

int main() {
    File *file = open_file("test.txt", "r");
    
    if (!file) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    // Do something with the file

    close_file(file);

    return EXIT_SUCCESS;
}
