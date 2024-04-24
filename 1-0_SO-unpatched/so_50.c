    len = strlen(context->packet);
    if ((sendto(context->socket, context->packet, len, 0, 
                NULL, 0)) != len) {
        perror("Failed to send");
        exit(-1);
    }