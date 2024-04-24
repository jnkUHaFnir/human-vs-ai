#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    const char *homedir = getenv("HOME");
    if (!homedir) {
        perror("Failed to get home directory");
        return -1;
    }

    char filePath[1024];
    snprintf(filePath, sizeof(filePath), "%s/Desktop/folder/file", homedir);

    int fd = open(filePath, O_RDONLY);
    if (fd == -1) {
        perror("Failed to open file");
        return -1;
    }

    // Do something with the file
    close(fd);
    return 0;
}
