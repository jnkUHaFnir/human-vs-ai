#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd1, fd2;
    size_t nbytes;
    ssize_t bytes_read;

    fd1 = open("file1.txt", O_RDONLY);
    if (fd1 == -1) {
        perror("Error opening file1.txt");
        return 1;
    }

    fd2 = open("file2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd2 == -1) {
        perror("Error opening file2.txt");
        return 1;
    }

    // Determine file size
    off_t file_size = lseek(fd1, 0, SEEK_END);
    lseek(fd1, 0, SEEK_SET);

    char *buf = malloc(file_size);
    if (buf == NULL) {
        perror("Error allocating memory");
        return 1;
    }

    bytes_read = read(fd1, buf, file_size);
    if (bytes_read == -1) {
        perror("Error reading from file1");
        free(buf);
        return 1;
    }

    if (write(fd2, buf, bytes_read) != bytes_read) {
        perror("Error writing to file2");
        free(buf);
        return 1;
    }

    free(buf);
    close(fd1);
    close(fd2);

    return 0;
}
