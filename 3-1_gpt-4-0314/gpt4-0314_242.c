typedef struct {
    size_t length;
    char *contents;
} Message;
Message message;
message.length = strlen(information_i_want_to_send) + 1;
message.contents = information_i_want_to_send;

size_t length_to_send = htonl(message.length);

send(ioSock, &length_to_send, sizeof(size_t), 0);
send(ioSock, message.contents, message.length, 0);
// Read the length of the message
size_t received_length;
recv(ioSock, &received_length, sizeof(size_t), 0);
size_t messagelength = ntohl(received_length);

// Allocate memory for the message string
char *buffer = (char *)malloc(messagelength);

// Read the message contents
size_t received = 0, n;
while (received < messagelength) {
    n = recv(ioSock, buffer + received, messagelength - received, 0);
    if (n <= 0) break;
    received += n;
}
free(buffer);
