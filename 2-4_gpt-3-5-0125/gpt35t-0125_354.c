int fd1;
int fd2;
size_t len;
size_t nbytes;
ssize_t bytes_read;

fd1 = open(file1, O_RDWR);

fd2 = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0644 );
char *buf;

// Get the size of the file
len = lseek(fd1, 0, SEEK_END);
lseek(fd1, 0, SEEK_SET);

buf = (char*)malloc(len);
if (buf == NULL) {
    printf("Memory allocation failed\n");
    return 1;
}

nbytes = len;
bytes_read = read(fd1, buf, nbytes);

write(fd2, buf, bytes_read); 

close(fd1);
close(fd2);

free(buf);

return 0;
