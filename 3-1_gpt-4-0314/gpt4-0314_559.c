#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int get_file_contents(const char *filename, char **content, size_t *content_size) {
    struct stat st;
    if (stat(filename, &st) != 0) {
        perror("stat");
        return -1;
    }

    // Check if file is larger than 4GB
    if ((size_t)st.st_size > (size_t)1 << 32) {
        fprintf(stderr, "File is too large!\n");
        return -1;
    }

    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("fopen");
        return -1;
    }

    *content_size = (size_t)st.st_size;
    *content = (char *)malloc(*content_size);

    // Read file content into the allocated memory
    if (fread(*content, 1, *content_size, file) != *content_size) {
        perror("fread");
        fclose(file);
        return -1;
    }

    fclose(file);
    return 0;
}

int main() {
    const char *filename = "example.txt";

    char *content;
    size_t content_size;

    if (get_file_contents(filename, &content, &content_size) != 0) {
        fprintf(stderr, "Failed to read file\n");
        return 1;
    }

    // Compare content with other character arrays or log it to a file

    free(content);
    return 0;
}
