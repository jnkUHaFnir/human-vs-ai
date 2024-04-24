#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_CONTENT_LENGTH 1024

struct Message {
    size_t length;
    char contents[MAX_CONTENT_LENGTH];
};

void send_message(int ioSock, struct Message* message) {
    // Serialize the message length into network byte order
    size_t netLength = htonl(message->length);

    // Send the length first
    send(ioSock, &netLength, sizeof(netLength), 0);

    // Send the message contents
    send(ioSock, message->contents, message->length, 0);
}

void receive_message(int ioSock, struct Message* message) {
    size_t netLength;
    recv(ioSock, &netLength, sizeof(netLength), 0);
    
    // Convert network byte order back to host byte order
    message->length = ntohl(netLength);

    // Receive the message contents
    recv(ioSock, message->contents, message->length, 0);
}

int main() {
    struct Message messageToSend;
    strcpy(messageToSend.contents, "Information to Send");
    messageToSend.length = strlen(messageToSend.contents);

    // Send message
    send_message(ioSock, &messageToSend);

    // Receive message
    struct Message receivedMessage;
    receive_message(ioSock, &receivedMessage);

    printf("Received Message: %s\n", receivedMessage.contents);

    return 0;
}
