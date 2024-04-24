#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#define CHUNK_SIZE 1024 // adjust the chunk size as needed

int main() {
    FILE *file;
    struct stat st;
    char *buffer;
    size_t fileSize, bytesRead;

    file = fopen("yourfile.txt", "rb");
    if (!file) {
        printf("Error opening file.\n");
        return 1;
    }

    // Get the file size
    stat("yourfile.txt", &st);
    fileSize = st.st_size;

    buffer = (char *)malloc(fileSize + 1);
    if (!buffer) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Read the file in chunks
    bytesRead = fread(buffer, 1, fileSize, file);
    buffer[fileSize] = '\0'; // Add null terminator

    if (bytesRead != fileSize) {
        printf("Error reading file.\n");
        free(buffer);
        fclose(file);
        return 1;
    }

    // Process the contents of the file

    printf("File contents: %s\n", buffer);

    free(buffer);
    fclose(file);

    return 0;
}
