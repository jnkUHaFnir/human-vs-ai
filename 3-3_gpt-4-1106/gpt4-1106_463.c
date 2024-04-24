// ...
/* send header */
size_t header_length = strlen(context->packet);
if ((send(context->socket, context->packet, header_length, 0)) != header_length) {
    perror("Failed to send");
    exit(-1);
}
// ...
