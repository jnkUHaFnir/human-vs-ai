#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <arpa/inet.h>

#define MAX_MESSAGE_LENGTH 1024

// Define your Message struct
struct Message {
    size_t length;
    char contents[MAX_MESSAGE_LENGTH - sizeof(size_t)];
};

// Serialize the Message struct into a buffer before sending
void serializeMessage(struct Message *msg, char *buffer) {
    size_t total_length = sizeof(size_t) + msg->length;
    memcpy(buffer, &total_length, sizeof(size_t)); // Copy total length first
    memcpy(buffer + sizeof(size_t), msg, msg->length); // Copy contents
}

// Deserialize the buffer into a Message struct after receiving
void deserializeMessage(char *buffer, struct Message *msg) {
    memcpy(&(msg->length), buffer, sizeof(size_t)); // Copy length first
    memcpy(msg, buffer + sizeof(size_t), msg->length); // Copy contents
}

int main() {
    // Example usage
    int ioSock; // Assume this is your socket file descriptor

    struct Message message;
    message.length = strlen("Hello, this is a test message!");
    strcpy(message.contents, "Hello, this is a test message!");

    // Serialize the message before sending
    char sendBuffer[MAX_MESSAGE_LENGTH + sizeof(size_t)];
    serializeMessage(&message, sendBuffer);

    // Send the serialized message
    send(ioSock, sendBuffer, sizeof(size_t) + message.length, 0);

    // Receive the serialized message
    char recvBuffer[MAX_MESSAGE_LENGTH + sizeof(size_t)];
    recv(ioSock, recvBuffer, sizeof(size_t), 0); // Receive the length first

    struct Message receivedMessage;
    deserializeMessage(recvBuffer, &receivedMessage);

    // Now you have the deserialized message in receivedMessage
    printf("Received message length: %zu\n", receivedMessage.length);
    printf("Received message contents: %s\n", receivedMessage.contents);

    return 0;
}
