int sgetline(int fd, char **out) {
    int buf_size = 128;
    int bytesloaded = 0;
    char buf[2];
    char *buffer = malloc(buf_size);
    char *newbuf;
    int size = buf_size;
    int pos = 0;

    assert(NULL != buffer);

    while (read(fd, buf, 1) > 0) {
        if (pos + 1 >= size) {
            size += buf_size;
            newbuf = realloc(buffer, size);
            if (NULL == newbuf) {
                fprintf(stderr, "sgetline() allocation failed!\n");
                free(buffer);
                exit(1);
            }
            buffer = newbuf;
        }

        if (buf[0] == '\n') {
            buffer[pos] = '\0';
            *out = buffer;
            return bytesloaded;
        }

        buffer[pos++] = buf[0];
        bytesloaded++;
    }

    *out = buffer;
    return bytesloaded;
}
