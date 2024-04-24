/* send header */
if (send(context->socket, context->packet, strlen(context->packet), 0) != strlen(context->packet)) {
    perror("Failed to send");
    exit(-1);
}

/* receive response */
while ((received = recv(context->socket, context->packet, BUFF_SIZE - 1, 0)) > 0) {
    context->packet[received] = '\0';
    printf("%s", context->packet);
}

if (received < 0) {
    perror("Failed to receive");
    exit(-1);
}
