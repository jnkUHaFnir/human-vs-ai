#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        // Construct the file path relative to the current working directory
        char filepath[1024];
        snprintf(filepath, sizeof(filepath), "%s/Desktop/folder/file", cwd);

        // Open the file
        int fd = open(filepath, O_RDONLY);
        if (fd == -1) {
            perror("Error opening the file");
            return 1;
        }

        // File opened successfully, continue processing

        // Don't forget to close the file descriptor when done with it
        close(fd);
    } else {
        perror("getcwd() error");
        return 1;
    }

    return 0;
}
