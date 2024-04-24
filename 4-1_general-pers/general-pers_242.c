#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

#define MAX_MESSAGE_SIZE 1024

struct Message {
    size_t length;
    char contents[MAX_MESSAGE_SIZE - sizeof(size_t)];
};

int sendMessage(int ioSock, struct Message *message) {
    if (send(ioSock, message, message->length, 0) == -1) {
        perror("Error sending message");
        return -1;
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

#define MAX_MESSAGE_SIZE 1024

struct Message {
    size_t length;
    char contents[MAX_MESSAGE_SIZE - sizeof(size_t)];
};

int receiveMessage(int ioSock, struct Message *message) {
    if (recv(ioSock, &(message->length), sizeof(size_t), MSG_WAITALL) <= 0) {
        perror("Error receiving message length");
        return -1;
    }
    
    size_t remainingLength = message->length - sizeof(size_t);
    size_t received = 0;
    
    while (received < remainingLength) {
        int bytesRead = recv(ioSock, message->contents + received, remainingLength - received, 0);
        
        if (bytesRead <= 0) {
            perror("Error receiving message content");
            return -1;
        }
        
        received += bytesRead;
    }
    
    return 0;
}
