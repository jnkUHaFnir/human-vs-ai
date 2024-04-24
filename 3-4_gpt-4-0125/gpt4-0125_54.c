#include <stdint.h>

struct Message {
    uint32_t length; // Always 4 bytes regardless of platform
    char contents[1024 - sizeof(uint32_t)];
};
uint32_t msgLength = htonl(sizeof(message.contents)); // Ensure network byte order
send(sockfd, &msgLength, sizeof(msgLength), 0); // Send the length first
send(sockfd, message.contents, sizeof(message.contents), 0); // Then send the actual message
uint32_t msgLength;
recv(sockfd, &msgLength, sizeof(msgLength), 0); // Receive the length first
msgLength = ntohl(msgLength); // Convert from network byte order to host byte order

char* buffer = malloc(msgLength); // Dynamically allocate the buffer of the exact size
recv(sockfd, buffer, msgLength, 0); // Then receive the actual message
ssize_t bytesRead = 0;
ssize_t result;
while (bytesRead < msgLength) {
    result = recv(sockfd, buffer + bytesRead, msgLength - bytesRead, 0);
    if (result == 0) {
        // Connection closed
        break;
    } else if (result < 0) {
        // Handle errors (e.g., would block, interrupted by signal, etc.)
        break;
    }
    bytesRead += result;
}
