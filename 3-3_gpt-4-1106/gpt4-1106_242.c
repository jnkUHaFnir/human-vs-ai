#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>

struct Message {
    size_t length;
    char contents[1024 - sizeof(size_t)];
};

// Define a function that ensures you're reading exactly 'len' bytes
ssize_t recv_all(int socket, void *buffer, size_t len, int flags) {
    size_t total_received = 0;
    ssize_t bytes_received;
    char *buffer_ptr = buffer;

    while (total_received < len) {
        bytes_received = recv(socket, buffer_ptr + total_received, len - total_received, flags);
        if (bytes_received <= 0) {
            // Handle errors or connection closed by client
            return bytes_received;
        }
        total_received += bytes_received;
    }

    return total_received;
}

int main(int argc, char *argv[]) {
    // This would be your previously established socket (ioSock)
    int ioSock = ...; // Socket should be connected with other side at this point

    struct Message message;
    // First, receive the 'length' part of the Message
    if (recv_all(ioSock, &message.length, sizeof(message.length), 0) == sizeof(message.length)) {
        // If the architecture is different between the two machines sharing structs,
        // You should convert the endianness if necessary here.

        // Now receive the 'contents' based on the 'length' received
        if (recv_all(ioSock, message.contents, message.length - sizeof(message.length), 0) >= 0) {
            // Successfully received the entire message
            // Process your message.contents here
        } else {
            // Handle error
        }
    } else {
        // Handle error: could not receive the length part
    }

    // Close the socket and clean up here...
    // ...

    return 0;
}
