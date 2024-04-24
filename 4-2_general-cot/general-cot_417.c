#define MAX_MESSAGE_LENGTH 1024

typedef struct {
    size_t length;
    char contents[MAX_MESSAGE_LENGTH];
} Message;
Message sendMessage;
// Populate sendMessage struct...

char serializedMessage[sizeof(Message)];
memcpy(serializedMessage, &sendMessage, sizeof(Message));

send(ioSock, serializedMessage, sizeof(Message), 0);
char receivedMessage[sizeof(Message)];
size_t bytesReceived = 0;

while (bytesReceived < sizeof(Message)) {
    size_t bytes = recv(ioSock, receivedMessage + bytesReceived, sizeof(Message) - bytesReceived, 0);
    if (bytes <= 0) {
        // Handle error or connection closure
    }
    
    bytesReceived += bytes;
}

Message received;
memcpy(&received, receivedMessage, sizeof(Message));
