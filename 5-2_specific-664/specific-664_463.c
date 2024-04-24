/* send header */
if ((send(context->socket, context->packet, strlen(context->packet), 0)) != strlen(context->packet)) {
    perror("Failed to send");
    exit(-1);
}

/* receive response */
do {
    received = recv(context->socket, context->packet, BUFF_SIZE - 1, 0);
    if (received < 0) {
        perror("Failed to receive");
        exit(-1);
    } else if (received == 0) {
        // Connection closed by the remote server
        break;
    }

    context->packet[received] = '\0';
    printf("%s", context->packet);

} while (1);
