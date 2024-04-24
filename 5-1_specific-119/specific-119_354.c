#define MAX_BUF_SIZE 1024

int fd1;
int fd2;
size_t nbytes;
ssize_t bytes_read;

fd1 = open(file1, O_RDONLY);
if (fd1 == -1) {
    perror("Error opening file1");
    return 1;
}

fd2 = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
if (fd2 == -1) {
    perror("Error opening file2");
    close(fd1);
    return 1;
}

char *buf = (char *)malloc(MAX_BUF_SIZE);
if (buf == NULL) {
    perror("Error allocating memory");
    close(fd1);
    close(fd2);
    return 1;
}

while ((bytes_read = read(fd1, buf, MAX_BUF_SIZE)) > 0) {
    if (write(fd2, buf, bytes_read) != bytes_read) {
        perror("Error writing to file2");
        free(buf);
        close(fd1);
        close(fd2);
        return 1;
    }
}

free(buf);
close(fd1);
close(fd2);

return 0;
