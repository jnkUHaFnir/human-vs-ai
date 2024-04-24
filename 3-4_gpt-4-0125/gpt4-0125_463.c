/* Adjusted send call */
int packet_len = snprintf( ... ); // Your existing snprintf call, capturing the return value
if (send(context->socket, context->packet, packet_len, 0) != packet_len) {
    perror("Failed to send");
    exit(-1);
}

/* Adjusted receive call */
received = recv(context->socket, context->packet, BUFF_SIZE, 0);
