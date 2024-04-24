#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024

// Define a simple message structure
struct Message {
    size_t length;
    char contents[BUFFER_SIZE - sizeof(size_t)];
};

// Function to send a message
void sendMessage(int socket, struct Message* message) {
    send(socket, message, message->length, 0);
}

// Function to receive a message
void receiveMessage(int socket, struct Message* message) {
    recv(socket, message, sizeof(struct Message), 0);
    while(message->length > 0) {
        ssize_t bytesReceived = recv(socket, message->contents, message->length, 0);
        if(bytesReceived < 0) {
            // Handle receive error
            break;
        }
        message->length -= bytesReceived;
    }
}

int main() {
    struct Message message;
    // Populate the message
    strcpy(message.contents, "information_i_want_to_send");
    message.length = sizeof(size_t) + strlen(message.contents) + 1; // +1 for null terminator

    // Create a socket and establish a connection (not shown here)

    // Sender side
    sendMessage(socket, &message);

    // Receiver side
    receiveMessage(socket, &message);

    // Process received message
    printf("Received message: %s\n", message.contents);

    // Close the socket (not shown here)

    return 0;
}
