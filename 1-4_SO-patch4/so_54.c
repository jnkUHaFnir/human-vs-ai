    typedef struct {
       uint32_t length;
       char contents[1020];
    } Message
    Message message;
    ssize_t bytes_read = recv_fixed_amount(sockfd, &(message.length), sizeof(message.length));
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
    bytes_read = recv_fixed_amount(sockfd, &(message.content), sizeof(message.content));
    if (bytes_read < 0) {
       perror("recv");
       exit(EXIT_FAILURE);
    }
    if (bytes_read != msg_size) {
       fprintf(stderr, "recv: Premature EOF.\n");
       exit(EXIT_FAILURE);
    }