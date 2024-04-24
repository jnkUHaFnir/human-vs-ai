    /* create header */
    snprintf(context->packet, BUFF_SIZE,
             "GET %s HTTP/1.1\r\n" \
             "Host: %s\r\n\r\n", 
             conf->request, conf->host);
    
    /* send header */
    if ((sendto(context->socket, context->packet, BUFF_SIZE, 0, 
                NULL, 0)) != BUFF_SIZE) {
        perror("Failed to send");
        exit(-1);
    }