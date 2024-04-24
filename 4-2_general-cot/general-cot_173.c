#include <stdio.h>
#include <unistd.h>
#include <libgen.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    char exe_path[4096];
    char *dir_path;
    char file_path[4096];

    if (realpath(argv[0], exe_path) == NULL) {
        perror("realpath");
        return 1;
    }

    dir_path = dirname(exe_path);
    snprintf(file_path, sizeof(file_path), "%s/Desktop/folder/file", dir_path);

    int fd = open(file_path, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // File opened successfully, do something with it

    close(fd);

    return 0;
}
