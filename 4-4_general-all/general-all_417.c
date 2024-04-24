#include <stdint.h>
#include <string.h>

void serializeMessage(struct Message* message, char* buffer) {
    size_t length = message->length;
    memcpy(buffer, &length, sizeof(size_t));
    memcpy(buffer + sizeof(size_t), message->contents, length - sizeof(size_t));
}
struct Message deserializeMessage(char* buffer) {
    struct Message message;
    memcpy(&message.length, buffer, sizeof(size_t));
    memcpy(message.contents, buffer + sizeof(size_t), message.length - sizeof(size_t));
    return message;
}
