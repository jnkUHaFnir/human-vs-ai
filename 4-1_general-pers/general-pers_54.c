#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <arpa/inet.h>

struct Message {
    size_t length;
    char contents[1024 - sizeof(size_t)];
};

// Function to serialize the Message struct into a byte stream
size_t serialize_message(struct Message *msg, char *buffer) {
    size_t length = sizeof(size_t) + msg->length;
    memcpy(buffer, &length, sizeof(size_t));
    memcpy(buffer + sizeof(size_t), msg->contents, msg->length);
    return length;
}

// Function to deserialize the byte stream into a Message struct
void deserialize_message(char *buffer, struct Message *msg) {
    memcpy(&(msg->length), buffer, sizeof(size_t));
    memcpy(msg->contents, buffer + sizeof(size_t), msg->length - sizeof(size_t));
}

int main() {
    struct Message message;
    message.length = strlen("information_i_want_to_send") + 1; // Include null terminator
    strcpy(message.contents, "information_i_want_to_send");

    // Serialization
    char buffer[1024];
    size_t buflen = serialize_message(&message, buffer);

    // In your socket code, send 'buffer' of 'buflen' bytes

    // Assume 'buffer' has been received on the server side
    struct Message received_message;
    deserialize_message(buffer, &received_message);

    printf("Received message: %s\n", received_message.contents);

    return 0;
}
