    n = read(newsockfd,buffer,255);
    if (n < 0) error("ERROR reading from socket");
    buffer[n]= '\0'; /* here */
    printf("Here is the message: %s\n",buffer);