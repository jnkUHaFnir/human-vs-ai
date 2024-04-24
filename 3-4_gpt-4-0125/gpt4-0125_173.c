#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    char *home = getenv("HOME");
    if (home == NULL) {
        fprintf(stderr, "Failed to get HOME directory\n");
        return 1;
    }

    char filepath[512]; // Ensure this is large enough for your path
    snprintf(filepath, sizeof(filepath), "%s/Desktop/folder/file", home);

    int fd = open(filepath, O_RDONLY);
    if (fd < 0) {
        perror("Failed to open file");
        return 1;
    }

    // Your file operations here

    close(fd);
    return 0;
}
