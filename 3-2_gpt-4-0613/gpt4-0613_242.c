struct MessageHeader {
    size_t length;
};

struct Message {
    struct MessageHeader header;
    char contents[1024 - sizeof(struct MessageHeader)];
};


ssize_t readn(int fd, void *buf, size_t n) {
    size_t nleft = n;
    ssize_t nread;
    char *ptr = buf;

    while (nleft > 0) {
        if ((nread = recv(fd, ptr, nleft, 0)) < 0) {
            if (errno == EINTR) {
                nread = 0;  /* and call read() again */
            } else {
                return -1;  /* error */
            }
        } else if (nread == 0) {
            break;  /* EOF */
        }

        nleft -= nread;
        ptr += nread;
    }

    return n - nleft;  /* return >= 0 */
}

int read_msg(int fd, struct Message *msg) {
    if (readn(fd, &(msg->header), sizeof(struct MessageHeader)) < 0) {
        return -1;
    }

    if (readn(fd, msg->contents, msg->header.length) < 0) {
        return -1;
    }

    return 0;
}
