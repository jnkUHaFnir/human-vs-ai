#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // for fixed-size data types

// Define the message structure
struct Message {
    uint32_t length;
    char contents[1024];
};

int main() {
    struct Message message;
    // Assuming information_i_want_to_send is a null-terminated string
    strcpy(message.contents, "information_i_want_to_send");
    message.length = strlen(message.contents); // Set the message length correctly

    // Send the message length
    send(ioSock, &message.length, sizeof(message.length), 0);
    // Send the message contents
    send(ioSock, message.contents, message.length, 0);

    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdint.h> // for fixed-size data types

// Define the message structure
struct Message {
    uint32_t length;
    char contents[1024];
};

int main() {
    struct Message message;

    // Receive the message length
    recv(ioSock, &message.length, sizeof(message.length), 0);

    // Receive the message contents
    int totalReceived = 0;
    int bytesReceived;
    while (totalReceived < message.length) {
        bytesReceived = recv(ioSock, message.contents + totalReceived, message.length - totalReceived, 0);
        if (bytesReceived <= 0) {
            // Handle error or connection closed
            break;
        }
        totalReceived += bytesReceived;
    }
    message.contents[totalReceived] = '\0'; // Add null terminator

    printf("Received message: %s\n", message.contents);

    return 0;
}
