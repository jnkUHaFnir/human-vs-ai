int fd1;
int fd2;
size_t len;
ssize_t bytes_read, bytes_written;

// Define the size of your buffer
len = 1024; // For example, 1024 bytes (you may choose a different size based on your needs)

fd1 = open(file1, O_RDONLY); // Open source file for reading only

fd2 = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
if (fd1 < 0 || fd2 < 0) {
    // Error handling: either file1 couldn't be opened or file2 couldn't be created/opened
    perror("Error opening files");
    return -1;
}

// Allocate memory for the buffer
char *buf = malloc(len * sizeof(char));
if (buf == NULL) {
    // Handle memory allocation failure
    perror("Memory allocation error");
    close(fd1);
    close(fd2);
    return -1;
}

// Read from file1 and write to file2
while ((bytes_read = read(fd1, buf, len)) > 0) {
    bytes_written = write(fd2, buf, bytes_read);
    if (bytes_written != bytes_read) {
        // Handle write error
        perror("Writing error");
        free(buf);
        close(fd1);
        close(fd2);
        return -1;
    }
}

// If the read call returned -1, there was an error
if (bytes_read == -1) {
    perror("Reading error");
}

// Free the allocated buffer memory
free(buf);

// Close file descriptors
close(fd1);
close(fd2);

return 0;
