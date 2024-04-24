struct Message {
    size_t length;
    char contents[1024 - sizeof(size_t)];
} message;

// Fill the message struct fields
message.length = sizeof(struct Message);
strcpy(message.contents, information_i_want_to_send);

// Serialize the message struct into a byte buffer
char buffer[sizeof(struct Message)];
memcpy(buffer, &message, sizeof(struct Message));

// Send the serialized buffer over the socket
send(ioSock, buffer, sizeof(struct Message), 0);
// Receive the serialized buffer
char buffer[sizeof(struct Message)];
recv(ioSock, buffer, sizeof(struct Message), 0);

// Deserialize the buffer into a Message struct
struct Message received_message;
memcpy(&received_message, buffer, sizeof(struct Message));

// Extract the fields from the received message
size_t received_length = received_message.length;
char received_contents[1024 - sizeof(size_t)];
strcpy(received_contents, received_message.contents);
