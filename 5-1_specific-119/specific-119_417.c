#include <stdio.h>
#include <string.h>

struct Message {
    size_t length;
    char contents[1024 - sizeof(size_t)];
};

// Function to serialize a Message struct into a byte stream
void serializeMessage(struct Message* msg, char* buffer) {
    size_t offset = 0;

    memcpy(buffer + offset, &msg->length, sizeof(size_t));
    offset += sizeof(size_t);

    memcpy(buffer + offset, msg->contents, msg->length - sizeof(size_t));
}

// Function to deserialize a byte stream into a Message struct
void deserializeMessage(char* buffer, struct Message* msg) {
    size_t offset = 0;

    memcpy(&msg->length, buffer + offset, sizeof(size_t));
    offset += sizeof(size_t);

    memcpy(msg->contents, buffer + offset, msg->length - sizeof(size_t));
}
// Client side
struct Message message;
// Populate your message struct

char buffer[sizeof(struct Message)];
serializeMessage(&message, buffer);

send(ioSock, buffer, sizeof(struct Message), 0);
// Server side
char buffer[sizeof(struct Message)];
recv(ioSock, buffer, sizeof(struct Message), 0);

struct Message receivedMessage;
deserializeMessage(buffer, &receivedMessage);
