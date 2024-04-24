// include headers

#define BUFFER_SIZE 256
#define MESSAGE_DELIMITER "\n"

int main(int argc, char *argv[]) {
    // socket setup

    char buffer[BUFFER_SIZE];
    bzero(buffer, BUFFER_SIZE);

    n = read(newsockfd, buffer, BUFFER_SIZE - 1); // read with size limit
    if (n < 0) 
        error("ERROR reading from socket");

    buffer[n] = '\0'; // null-terminate the received message

    // process the received message
    char *msg = strtok(buffer, MESSAGE_DELIMITER); // extract the message
    while (msg != NULL) {
        printf("Here is the message: %s\n", msg);

        // handle the message

        msg = strtok(NULL, MESSAGE_DELIMITER); // get the next message
    }

    n = write(newsockfd, "U got your message", 18);
    if (n < 0) 
        error("ERROR writing to socket");

    // close connections
}
// include headers

#define BUFFER_SIZE 256
#define MESSAGE_DELIMITER "\n"

int main(int argc, char *argv[]) {
    // socket setup

    char buffer[BUFFER_SIZE];
    bzero(buffer, BUFFER_SIZE);

    printf("Please enter the message: ");
    fgets(buffer, BUFFER_SIZE - 1, stdin); // read with size limit
    strcat(buffer, MESSAGE_DELIMITER); // add message delimiter

    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) 
        error("ERROR writing to socket");

    bzero(buffer, BUFFER_SIZE);

    n = read(sockfd, buffer, BUFFER_SIZE - 1); // read with size limit
    if (n < 0) 
        error("ERROR reading from socket");

    buffer[n] = '\0'; // null-terminate the received message
    printf("%s\n", buffer); // print the received message

    // close connection
}
