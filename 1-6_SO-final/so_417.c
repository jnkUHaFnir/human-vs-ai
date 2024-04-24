    uint32_t msg_size;
    ssize_t bytes_read = recv_fixed_amount(sockfd, &msg_size, sizeof(msg_size));
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
    char* msg = malloc(msg_size);
    if (!msg) {
       perror("malloc");
       exit(EXIT_FAILURE);
    }
    bytes_read = recv_fixed_amount(sockfd, msg, msg_size);
    if (bytes_read < 0) {
       perror("recv");
       exit(EXIT_FAILURE);
    }
    if (bytes_read != msg_size) {
       fprintf(stderr, "recv: Premature EOF.\n");
       exit(EXIT_FAILURE);
    }