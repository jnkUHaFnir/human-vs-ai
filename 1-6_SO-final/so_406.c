    size_t len;
    char buf[1000];
    fgets(buf, sizeof buf, stdin);
    buflen = strlen(buf);
    if (len) {
        if (buf[len - 1] == '\n') {
            buf[--len] = '\0'; /* adjust len and remove trailing newline */
        } else {
            /* something bad hapenned */
            if (len == sizeof buf - 1) {
                /* possibly large input */
            } else {
                /* small input */
            }
        }
    } else {
        /* no characters read at all */
    }