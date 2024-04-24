char *buf[len];
// Define a buffer size
#define BUFFER_SIZE 1024

// Allocate memory for the buffer
char *buf = malloc(BUFFER_SIZE);
if (buf == NULL) {
    // Handle memory allocation failure
    perror("Malloc failed");
    close(fd1);
    close(fd2);
    return 1;
}

nbytes = BUFFER_SIZE;  // Now nbytes holds the size of the buffer

while ((bytes_read = read(fd1, buf, nbytes)) > 0) {
    if (write(fd2, buf, bytes_read) != bytes_read) {
        // Handle incomplete write
        perror("Write error");
        break;
    }
}

// Free the allocated memory
free(buf);
write(fd2, &bytes_read, nbytes);
