...
printf("Please enter the message: ");
bzero(buffer,256);
fgets(buffer,255,stdin);

char formatted_message[256];
sprintf(formatted_message, "%d:%s", strlen(buffer), buffer);

n = write(sockfd,formatted_message,strlen(formatted_message));
...
...
bzero(buffer,256);
n = read(newsockfd,buffer,255);
if (n < 0) error("ERROR reading from socket");

int length;
char message[256];
sscanf(buffer, "%d:%s", &length, message);

printf("Here is the message: %s\n", message);

n = write(newsockfd,"U got your message",18);
...
