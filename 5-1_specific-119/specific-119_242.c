#include <stdio.h>
#include <string.h>

struct Message {
    size_t length;
    char contents[1024 - sizeof(size_t)];
};

void serializeMessage(struct Message* message, char* buffer) {
    memcpy(buffer, &(message->length), sizeof(size_t));
    memcpy(buffer + sizeof(size_t), message->contents, message->length - sizeof(size_t));
}

void deserializeMessage(char* buffer, struct Message* message) {
    memcpy(&(message->length), buffer, sizeof(size_t));
    memcpy(message->contents, buffer + sizeof(size_t), message->length - sizeof(size_t));
}

int main() {
    struct Message message;
    char buffer[1024];

    // Populate your message
    message.length = sizeof(struct Message);
    strcpy(message.contents, "information_i_want_to_send");

    // Serialize the message before sending
    serializeMessage(&message, buffer);

    // You can now send 'buffer' using send() in your client application

    // At the server side, you will receive 'buffer' using recv()

    // Deserialize the received buffer to reconstruct the message
    struct Message receivedMessage;
    deserializeMessage(buffer, &receivedMessage);

    printf("Received message length: %zu\n", receivedMessage.length);
    printf("Received message contents: %s\n", receivedMessage.contents);

    return 0;
}
