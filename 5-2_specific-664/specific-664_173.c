#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    const char *homeDir = getenv("HOME");
    if (homeDir == NULL) {
        fprintf(stderr, "Unable to get home directory\n");
        return 1;
    }

    char filePath[100];
    snprintf(filePath, sizeof(filePath), "%s/Desktop/folder/file", homeDir);

    int fd = open(filePath, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    printf("File opened successfully\n");

    // Add your file processing logic here

    close(fd);
    return 0;
}
