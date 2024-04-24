#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

struct Message {
    size_t length;
    char contents[1024 - sizeof(size_t)];
};

// Serialize struct Message into a byte buffer
void serializeMessage(struct Message* msg, char* buffer) {
    size_t length = msg->length;
    memcpy(buffer, &length, sizeof(size_t));
    memcpy(buffer + sizeof(size_t), &(msg->contents), msg->length);
}

// Deserialize byte buffer into struct Message
void deserializeMessage(struct Message* msg, char* buffer) {
    size_t length;
    memcpy(&length, buffer, sizeof(size_t));
    msg->length = length;
    memcpy(&(msg->contents), buffer + sizeof(size_t), msg->length);
}

int main() {
    // Creating a sample message
    struct Message message;
    message.length = strlen("Hello, this is a test message!");
    strcpy(message.contents, "Hello, this is a test message!");

    // Serialize the message
    char buffer[sizeof(struct Message)];
    serializeMessage(&message, buffer);

    // Send the buffer using send function

    // On the receiving side, receive the buffer using recv function

    // Deserialize the received buffer
    struct Message receivedMessage;
    deserializeMessage(&receivedMessage, buffer);

    // Now you have the received message in the 'receivedMessage' struct
    printf("Received Message: Length: %zu, Contents: %s\n", receivedMessage.length, receivedMessage.contents);

    return 0;
}
