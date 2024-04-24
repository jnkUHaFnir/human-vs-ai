#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    const char *homedir = getenv("HOME");
    if (homedir == NULL) {
        perror("getenv");
        return 1;
    }
    
    char path[1024];
    snprintf(path, sizeof(path), "%s/Desktop/folder/file", homedir);
    
    int fd = open(path, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Do something with the open file descriptor (fd)
    
    close(fd); // Always remember to close the file descriptor when done
    return 0;
}
