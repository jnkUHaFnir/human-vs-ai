int fd1;
int fd2;
size_t nbytes;
ssize_t bytes_read;
char *buf;

fd1 = open(file1, O_RDWR);

fd2 = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);

// Check if file opened successfully
if (fd1 == -1 || fd2 == -1) {
    perror("open");
    return 1;
}

// Allocate memory for the buffer
struct stat st;
fstat(fd1, &st);
nbytes = st.st_size;
buf = malloc(nbytes);

// Check if memory allocation was successful
if (buf == NULL) {
    perror("malloc");
    return 1;
}

bytes_read = read(fd1, buf, nbytes);

// Check if read operation was successful
if (bytes_read == -1) {
    perror("read");
    return 1;
}

write(fd2, buf, bytes_read);

// Free dynamically allocated memory
free(buf);

close(fd1);
close(fd2);

return 0;
