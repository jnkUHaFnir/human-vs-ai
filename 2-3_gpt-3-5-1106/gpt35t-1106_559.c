#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

char* readFile(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    struct stat st;
    if (stat(filename, &st) != 0) {
        perror("Error getting file stats");
        fclose(file);
        return NULL;
    }
    size_t fileSize = st.st_size;

    char* buffer = (char*)malloc(fileSize + 1);
    if (buffer == NULL) {
        perror("Error allocating memory");
        fclose(file);
        return NULL;
    }

    size_t bytesRead = fread(buffer, 1, fileSize, file);
    if (bytesRead != fileSize) {
        perror("Error reading file");
        free(buffer);
        fclose(file);
        return NULL;
    }
    buffer[fileSize] = '\0'; // Add null terminator

    fclose(file);
    return buffer;
}

int main() {
    const char* filename = "test.txt";
    char* content = readFile(filename);
    if (content != NULL) {
        // Do something with the contents
        printf("File contents: %s\n", content);
        free(content); // Don't forget to free the memory
    } else {
        printf("Error reading file\n");
    }

    return 0;
}
