#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd1;
    int fd2;
    size_t len = 1024; // Set a reasonable length or retrieve it dynamically
    size_t nbytes;
    ssize_t bytes_read;

    fd1 = open("file1.txt", O_RDONLY);
    if (fd1 == -1) {
        perror("Error opening file1");
        return 1;
    }

    fd2 = open("file2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd2 == -1) {
        perror("Error opening file2");
        close(fd1);
        return 1;
    }

    char *buf = (char *)malloc(len * sizeof(char));
    if (buf == NULL) {
        perror("Memory allocation failed");
        close(fd1);
        close(fd2);
        return 1;
    }

    while ((bytes_read = read(fd1, buf, len)) > 0) {
        if (write(fd2, buf, bytes_read) != bytes_read) {
            perror("Error writing to file2");
            close(fd1);
            close(fd2);
            free(buf);
            return 1;
        }
    }

    free(buf);
    close(fd1);
    close(fd2);

    return 0;
}
