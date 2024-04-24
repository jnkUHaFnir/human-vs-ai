char *buf = malloc(len * sizeof(char)); // Allocate len bytes

if(buf == NULL) {
   // handle error, e.g. print an error message and return or exit 
}

ssize_t bytes_read = read(fd1, buf, len);  // notice its len not nbytes

if(bytes_read == -1) {
   // handle error
}

ssize_t bytes_written = write(fd2, buf, bytes_read);  // notice its buf and bytes_read not &bytes_read and nbytes

if(bytes_written != bytes_read) {
   // handle error
}

free(buf);  // Release the allocated memory
