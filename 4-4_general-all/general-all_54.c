#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

struct Message {
    size_t length;
    char contents[1024]; // Assuming contents size is 1024 bytes
};

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    
    struct Message message;
    // Populate the message struct
    message.length = strlen("Information I want to send");
    strcpy(message.contents, "Information I want to send");
    
    // Send the message struct
    send(sock, &message, sizeof(message), 0);
    
    return 0;
}
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>

struct Message {
    size_t length;
    char contents[1024]; // Assuming contents size is 1024 bytes
};

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    struct Message received_message;
    // Receive the message struct
    recv(sock, &received_message, sizeof(received_message), 0);
    
    // Process the received message
    printf("Received message length: %zu\n", received_message.length);
    printf("Received message contents: %s\n", received_message.contents);
    
    return 0;
}
