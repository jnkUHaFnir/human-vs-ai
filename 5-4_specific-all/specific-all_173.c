#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    const char *file_path = argv[1];
    int fd = open(file_path, O_RDONLY);
    
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // File opened successfully, do something with it

    close(fd);

    return 0;
}
