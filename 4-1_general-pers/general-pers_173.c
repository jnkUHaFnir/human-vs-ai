#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    char filepath[1024];
    const char* home_dir = getenv("HOME");

    if (home_dir == NULL) {
        printf("Error: HOME environment variable not set\n");
        return 1;
    }

    snprintf(filepath, sizeof(filepath), "%s/Desktop/folder/file", home_dir);

    int fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // File opened successfully, proceed with reading the file

    close(fd);

    return 0;
}
