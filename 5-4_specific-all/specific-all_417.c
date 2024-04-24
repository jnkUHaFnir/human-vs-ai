// Assume message is your struct Message

// Serialize the struct into a byte array
char buffer[sizeof(struct Message)];
memcpy(buffer, &message, sizeof(struct Message));

// Send the byte array over the network
send(ioSock, buffer, sizeof(struct Message), 0);
// Receive data into a byte array
char buffer[sizeof(struct Message)];
recv(ioSock, buffer, sizeof(struct Message), 0);

// Deserialize the byte array back into the struct
struct Message receivedMessage;
memcpy(&receivedMessage, buffer, sizeof(struct Message));

// Now you can access receivedMessage.length and receivedMessage.contents
