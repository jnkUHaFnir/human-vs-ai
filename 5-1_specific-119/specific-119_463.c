/* receive response */
do {
    if ((received = recv(context->socket, context->packet, BUFF_SIZE, 0)) < 0) {

        /* Handle the error */
        perror("Failed to receive");
        exit(-1);
    }

    if (received > 0) {
        context->packet[received] = '\0';
        printf("%s", context->packet);
    }

} while (received > 0);
