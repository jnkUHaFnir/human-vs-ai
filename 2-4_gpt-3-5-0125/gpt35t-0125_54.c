struct Message {
    size_t length; // Total length of the message
    char contents[1024]; // Actual message content
} message;

// Fill in the message content
// Set the length of the message
message.length = sizeof(message);

// Send the message
send(ioSock, &message, message.length, 0);
struct Message {
    size_t length; // Total length of the message
    char contents[1024]; // Actual message content
} message;

// Receive the message
recv(ioSock, &message, sizeof(message), 0);

// Extract the message length
size_t messageLength = message.length;
size_t bytesReceived = sizeof(message);

// Loop until the entire message is received
while (bytesReceived < messageLength) {
    bytesReceived += recv(ioSock, &message.contents[bytesReceived - sizeof(size_t)], messageLength - bytesReceived, 0);
}
