#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define MAX_MESSAGE_LENGTH 1024

struct Message {
    uint32_t length;
    char contents[MAX_MESSAGE_LENGTH];
};

// Prepare the message
struct Message message;
message.length = strlen(information_i_want_to_send);
strcpy(message.contents, information_i_want_to_send);

// Send the message
send(ioSock, &message, sizeof(struct Message), 0);
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define MAX_MESSAGE_LENGTH 1024

struct Message {
    uint32_t length;
    char contents[MAX_MESSAGE_LENGTH];
};

// Receive the message
struct Message message;
recv(ioSock, &message, sizeof(struct Message), 0);

// Loop until entire message is received
while (received < message.length) {
    received += recv(ioSock, message.contents + received, MAX_MESSAGE_LENGTH - received, 0);
}
