char *buf = malloc(nbytes);
char buf[nbytes];
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd1;
    int fd2;
    size_t nbytes;
    ssize_t bytes_read;

    fd1 = open(file1, O_RDWR);
    fd2 = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    // Allocate a dynamic buffer
    nbytes = 4096;  // Example size, adjust as needed
    char *buf = malloc(nbytes);

    bytes_read = read(fd1, buf, nbytes);
    write(fd2, buf, bytes_read);

    close(fd1);
    close(fd2);

    free(buf);  // Free the dynamically allocated memory

    return 0;
}
