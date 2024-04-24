// Sender side
struct Message {
    size_t length;
    char contents[MAX_CONTENT_SIZE];
} message;

// Serialize your message
// Assume serialize_message serializes the Message struct into a buffer
size_t message_length;
char buffer[MAX_BUFFER_SIZE];
serialize_message(&message, buffer, &message_length);

// Send the serialized message over the network
send(ioSock, buffer, message_length, 0);

// Receiver side
char recv_buffer[MAX_BUFFER_SIZE];
size_t total_received = 0;
size_t expected_length;

// Loop until the entire message is received
while (total_received < sizeof(size_t)) {
    ssize_t received = recv(ioSock, &recv_buffer[total_received], sizeof(size_t) - total_received, 0);
    if (received <= 0) {
        // Handle error or connection closed
    }
    total_received += received;
}

// Extract message length from the received data
expected_length = *((size_t*)recv_buffer);

// Loop until the entire message is received
while (total_received < expected_length) {
    ssize_t received = recv(ioSock, &recv_buffer[total_received], expected_length - total_received, 0);
    if (received <= 0) {
        // Handle error or connection closed
    }
    total_received += received;
}

// Deserialize the received message
// Assume deserialize_message deserializes the buffer into a Message struct
struct Message received_message;
deserialize_message(recv_buffer, &received_message);
