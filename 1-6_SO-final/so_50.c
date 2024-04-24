    if ((sendto(context->socket, context->packet, strlen(context->packet), 0, 
                NULL, 0)) != BUFF_SIZE) {
        perror("Failed to send");
        exit(-1);
    }