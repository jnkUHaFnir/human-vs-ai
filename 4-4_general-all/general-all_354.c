#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd1, fd2;
    ssize_t bytes_read;

    fd1 = open("file1", O_RDONLY);
    if (fd1 == -1) {
        perror("Error opening file1");
        return 1;
    }

    fd2 = open("file2", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd2 == -1) {
        perror("Error opening file2");
        close(fd1);
        return 1;
    }

    off_t offset = 0;
    char buf[4096]; // You can adjust the buffer size as needed

    while ((bytes_read = read(fd1, buf, sizeof(buf))) > 0) {
        if (write(fd2, buf, bytes_read) != bytes_read) {
            perror("Error writing to file2");
            close(fd1);
            close(fd2);
            return 1;
        }
        offset += bytes_read;
    }

    if (bytes_read == -1) {
        perror("Error reading from file1");
    }

    close(fd1);
    close(fd2);

    return 0;
}
