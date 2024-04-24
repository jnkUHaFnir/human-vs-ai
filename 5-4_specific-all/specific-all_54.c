struct Message {
    size_t length;
    char contents[1024 - sizeof(size_t)];
} message;

// Serialization
char serialized_data[sizeof(struct Message)];
memcpy(serialized_data, &message, sizeof(struct Message));

// Sending the serialized data
send(ioSock, serialized_data, sizeof(struct Message), 0);
// Receiving the serialized data
char serialized_data[sizeof(struct Message)];
recv(ioSock, serialized_data, sizeof(struct Message), 0);

// Deserialization
struct Message received_message;
memcpy(&received_message, serialized_data, sizeof(struct Message));
