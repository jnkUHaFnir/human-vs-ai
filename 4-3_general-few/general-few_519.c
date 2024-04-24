int sgetline(int fd, char **out) {
    int buf_size = 128;
    int bytesloaded = 0;
    char buf[2];
    char *buffer = malloc(buf_size);
    char *newbuf;
    int size = buf_size;

    assert(NULL != buffer);

    while (read(fd, buf, 1) > 0) {
        buf[1] = '\0';

        if (buf[0] == '\r' || buf[0] == '\n') {
            if (buf[0] == '\r') {
                // Check if the next character is newline
                if (read(fd, buf, 1) > 0 && buf[0] == '\n') {
                    strcat(buffer, "\r\n");
                } else {
                    strcat(buffer, "\r");
                    lseek(fd, -1, SEEK_CUR); // Move back one character
                }
            } else {
                strcat(buffer, "\n");
            }
            
            *out = buffer;
            return bytesloaded;
        }

        strcat(buffer, buf);
        bytesloaded++;

        if (bytesloaded >= size) {
            size += buf_size;
            newbuf = realloc(buffer, size);

            if (NULL != newbuf) {
                buffer = newbuf;
            } else {
                printf("sgetline() allocation failed!\n");
                exit(1);
            }
        }
    }

    *out = buffer;
    return bytesloaded;
}
