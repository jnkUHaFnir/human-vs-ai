#include <stdio.h>
#include <stdlib.h>

char *read_input(const char *file) {
    FILE *fp = fopen(file, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *buffer = (char *)malloc(file_size + 1);
    if (!buffer) {
        perror("Error allocating memory");
        fclose(fp);
        return NULL;
    }

    size_t bytes_read = fread(buffer, 1, file_size, fp);
    if (bytes_read < file_size) {
        perror("Error reading file");
        free(buffer);
        fclose(fp);
        return NULL;
    }

    buffer[bytes_read] = '\0';

    fclose(fp);
    return buffer;
}

int main() {
    const char *file = "example.txt";
    char *file_content = read_input(file);
    if (file_content) {
        printf("File content: %s\n", file_content);
        free(file_content);
    }

    return 0;
}
