char *buf = malloc(nbytes);
if (buf == NULL) {
    // Handle malloc failure
}
free(buf);
``` 

This will allocate contiguous memory to store the data read from file1 and then you can use this buffer to write to file2.
