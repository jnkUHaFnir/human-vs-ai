// Serialization function to convert Message struct to a byte buffer
void serializeMessage(struct Message* msg, char* buffer) {
    // Copy length to buffer
    memcpy(buffer, &(msg->length), sizeof(size_t));
    // Copy contents to buffer right after length
    memcpy(buffer + sizeof(size_t), &(msg->contents), msg->length - sizeof(size_t));
}

// Sending the serialized message through a socket
// message is an instance of struct Message
char buffer[1024];
serializeMessage(&message, buffer);
send(ioSock, buffer, 1024, 0);
// Deserialization function to convert byte buffer to Message struct
void deserializeMessage(char* buffer, struct Message* msg) {
    // Copy length from buffer
    memcpy(&(msg->length), buffer, sizeof(size_t));
    // Copy contents from buffer right after length
    memcpy(&(msg->contents), buffer + sizeof(size_t), msg->length - sizeof(size_t));
}

// Receiving and deserializing the message from the socket
char buffer[1024];
recv(ioSock, buffer, 1024, 0);
struct Message receivedMessage;
deserializeMessage(buffer, &receivedMessage);
