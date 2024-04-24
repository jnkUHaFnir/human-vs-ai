#include <stdint.h>
#include <arpa/inet.h>

struct Message {
    uint32_t length;
    char contents[1024];
};

// Assuming you have your socket `ioSock` set up
struct Message message;
message.length = sizeof(message.contents);
memcpy(message.contents, information_i_want_to_send, strlen(information_i_want_to_send));

// Sending the struct over the socket (assuming ioSock is a valid socket descriptor)
send(ioSock, (void*)&message, sizeof(message), 0);
#include <stdint.h>
#include <arpa/inet.h>

// Define endianness for a consistent format
#define NETWORK_BYTE_ORDER 1

struct Message {
    uint32_t length;
    char contents[1024];
};

struct Message message;

// Receiving the struct from the socket
recv(ioSock, (void*)&message, sizeof(message), 0);

// Ensure endianness conversion if needed
#ifdef NETWORK_BYTE_ORDER
    message.length = ntohl(message.length);
#endif

// Loop recv until all data is received
uint32_t totalReceived = 0;
while (totalReceived < message.length) {
    int received = recv(ioSock, message.contents + totalReceived, message.length - totalReceived, 0);
    if (received == -1) {
        // handle error
        break;
    }
    totalReceived += received;
}

// Use the received message
