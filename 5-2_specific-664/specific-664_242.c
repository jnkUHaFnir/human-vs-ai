#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_MESSAGE_SIZE 1024

struct Message {
    size_t length;
    char contents[MAX_MESSAGE_SIZE - sizeof(size_t)];
};

// Function to serialize a Message struct into a buffer
void serializeMessage(struct Message* msg, char* buffer) {
    size_t totalLength = sizeof(size_t) + msg->length;
    memcpy(buffer, &totalLength, sizeof(size_t));
    buffer += sizeof(size_t);
    memcpy(buffer, msg, msg->length);
}

// Function to deserialize a buffer into a Message struct
void deserializeMessage(char* buffer, size_t bufferSize, struct Message* msg) {
    size_t totalLength;
    memcpy(&totalLength, buffer, sizeof(size_t));

    if (totalLength > bufferSize) {
        // Handle error - buffer size insufficient for message
        return;
    }

    memcpy(msg, buffer + sizeof(size_t), totalLength - sizeof(size_t));
}

int main() {
    // Example usage
    struct Message message;
    message.length = strlen("Hello, this is the message you want to send");
    strcpy(message.contents, "Hello, this is the message you want to send");

    // Serialize the Message struct
    char buffer[MAX_MESSAGE_SIZE];
    serializeMessage(&message, buffer);

    // Send the buffer over the socket
    // Example code for sending over socket is required here

    // Receive the buffer on the server side
    // Example code for receiving over socket is required here

    // Deserialize the buffer back into a Message struct
    struct Message receivedMessage;
    deserializeMessage(buffer, sizeof(buffer), &receivedMessage);

    printf("Received Message: %s\n", receivedMessage.contents);

    return 0;
}
