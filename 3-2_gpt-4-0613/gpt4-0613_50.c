// Use strlen to get the exact size of the message, don't send BUFF_SIZE blindly.
size_t len = strlen(context->packet);

// Use send instead of sendto for TCP.
if (send(context->socket, context->packet, len, 0) != len) {
    perror("Failed to send");
    exit(-1);
}
"GET %s HTTP/1.1\r\n" \
"Host: %s\r\n" \
"Connection: keep-alive\r\n\r\n", 
conf->request, conf->host
