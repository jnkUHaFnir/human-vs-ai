#include <stdio.h>
#include <string.h>
#include <stdint.h>

// Define your Message struct
struct Message {
    size_t length;
    char contents[1024 - sizeof(size_t)];
};

// Function to serialize Message struct into a byte buffer
void serializeMessage(struct Message *msg, char *buffer) {
    size_t offset = 0;

    memcpy(buffer + offset, &msg->length, sizeof(size_t));
    offset += sizeof(size_t);
    memcpy(buffer + offset, msg->contents, msg->length - sizeof(size_t));
}

// Function to deserialize byte buffer into Message struct
void deserializeMessage(char *buffer, struct Message *msg) {
    size_t offset = 0;

    memcpy(&msg->length, buffer + offset, sizeof(size_t));
    offset += sizeof(size_t);
    memcpy(msg->contents, buffer + offset, msg->length - sizeof(size_t));
}

int main() {
    struct Message message;
    message.length = sizeof(struct Message);
    char information_i_want_to_send[] = "Hello, World!";
    strncpy(message.contents, information_i_want_to_send, sizeof(message.contents));

    // Serialization
    char serialized[sizeof(struct Message)];
    serializeMessage(&message, serialized);

    // Code to send 'serialized' over the network

    // Deserialization
    struct Message receivedMessage;
    deserializeMessage(serialized, &receivedMessage);

    printf("Received Message: %s\n", receivedMessage.contents);

    return 0;
}
