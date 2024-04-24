/* create header with keep-alive */
snprintf(context->packet, BUFF_SIZE,
         "GET %s HTTP/1.1\r\n" \
         "Host: %s\r\n" \
         "Connection: keep-alive\r\n\r\n",
         conf->request, conf->host);
