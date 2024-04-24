    typedef struct {
       uint32_t length;
       char contents[];
    } Message
    uint32_t contents_size;
    ssize_t bytes_read = recv_fixed_amount(sockfd, &contents_size, sizeof(contents_size));
    if (bytes_read == 0) {
       printf("EOF reached\n");
       exit(EXIT_SUCCESS);
    }
    if (bytes_read < 0) {
       perror("recv");
       exit(EXIT_FAILURE);
    }
    if (bytes_read != sizeof(msg_size)) {
       fprintf(stderr, "recv: Premature EOF.\n");
       exit(EXIT_FAILURE);
    }
    Message *message = malloc(sizeof(Message)+contents_size);
    if (!message) {
       perror("malloc");
       exit(EXIT_FAILURE);
    }
    message->length = contents_size;
    bytes_read = recv_fixed_amount(sockfd, &(message->contents), contents_size);
    if (bytes_read < 0) {
       perror("recv");
       exit(EXIT_FAILURE);
    }
    if (bytes_read != contents_size) {
       fprintf(stderr, "recv: Premature EOF.\n");
       exit(EXIT_FAILURE);
    }