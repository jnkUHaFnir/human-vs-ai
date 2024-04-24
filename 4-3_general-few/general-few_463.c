/* receive response */
do {
    if ((received = recvfrom(context->socket, context->packet, BUFF_SIZE, 0, NULL, NULL)) < 0) {
        perror("Failed to receive");
        exit(-1);
    }

    if (received >= 0) {
        context->packet[received] = '\0';
        printf("%s", context->packet);
    }

} while (received > 0);

/* close socket */
close(context->socket);
