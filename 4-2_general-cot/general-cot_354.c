#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd1;
    int fd2;
    size_t nbytes;
    ssize_t bytes_read;

    fd1 = open(file1, O_RDONLY);
    fd2 = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if(fd1 == -1 || fd2 == -1) {
        perror("Error opening file");
        return 1;
    }

    // Determine file size for dynamic allocation
    off_t file_size = lseek(fd1, 0, SEEK_END);
    lseek(fd1, 0, SEEK_SET);

    char *buf = (char *)malloc(file_size);
    if (!buf) {
        perror("Memory allocation failed");
        return 1;
    }

    bytes_read = read(fd1, buf, file_size);
    if (bytes_read == -1) {
        perror("Error reading from file");
        free(buf);
        close(fd1);
        close(fd2);
        return 1;
    }

    write(fd2, buf, bytes_read);

    free(buf);
    close(fd1);
    close(fd2);

    return 0;
}
