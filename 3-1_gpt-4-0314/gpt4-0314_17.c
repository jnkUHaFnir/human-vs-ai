// ...
    printf("Please enter the message: ");
    bzero(buffer, 256);
    fgets(buffer, 255, stdin);
    
    // Implement protocol
    int msg_len = strlen(buffer);
    int total_len = htonl(msg_len);
    char msg_header[4];
    memcpy(msg_header, &total_len, sizeof(total_len));

    n = write(sockfd, msg_header, sizeof(msg_header));
    if (n < 0)
        error("ERROR writing message header to socket");

    n = write(sockfd, buffer, msg_len);
    if (n < 0)
        error("ERROR writing to socket");
// ...
// ...
    // Read message header first
    n = read(newsockfd, buffer, 4);
    if (n < 0)
        error("ERROR reading message header from socket");
    
    int total_len = 0;
    memcpy(&total_len, buffer, 4);
    total_len = ntohl(total_len);

    bzero(buffer, 256);
    n = read(newsockfd, buffer, total_len);
    if (n < 0)
        error("ERROR reading from socket");
// ...
