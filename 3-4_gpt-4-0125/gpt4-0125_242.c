uint32_t message_length = htonl(strlen(information_i_want_to_send)); // Assumes information_i_want_to_send is a string for simplicity.
send(ioSock, &message_length, sizeof(message_length), 0);
send(ioSock, information_i_want_to_send, strlen(information_i_want_to_send), 0);
uint32_t message_length;
recv(ioSock, &message_length, sizeof(message_length), MSG_WAITALL); // MSG_WAITALL tries to fill the buffer.
message_length = ntohl(message_length); // Convert back to host byte order.

char* buffer = malloc(message_length+1); // +1 for null terminator if it's a string we're dealing with.
recv(ioSock, buffer, message_length, MSG_WAITALL);
buffer[message_length] = '\0'; // Null-terminate if it's a string.
total_received = 0;
while (total_received < message_length) {
    ssize_t received = recv(ioSock, buffer+total_received, message_length-total_received, 0);
    if (received <= 0) { 
        // Handle error or disconnection.
        break; 
    }
    total_received += received;
}
