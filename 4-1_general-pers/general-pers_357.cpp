#include <iostream>
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

class Socket {
private:
    int sockfd;

public:
    Socket() : sockfd(-1) {}

    void create() {
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1) {
            perror("Error creating socket");
            exit(EXIT_FAILURE);
        }
    }

    void connect(const std::string& address, int port) {
        struct sockaddr_in serverAddr;
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = htons(port);
        inet_pton(AF_INET, address.c_str(), &serverAddr.sin_addr);

        if (::connect(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
            perror("Error connecting to server");
            exit(EXIT_FAILURE);
        }
    }

    void send(const std::string& message) {
        if (::send(sockfd, message.c_str(), message.length(), 0) == -1) {
            perror("Error sending data");
            exit(EXIT_FAILURE);
        }
    }

    ~Socket() {
        if (sockfd != -1) {
            close(sockfd);
        }
    }
};

int main() {
    Socket socket;
    socket.create();
    socket.connect("127.0.0.1", 8080);
    socket.send("POST / HTTP/1.1\r\n\r\n");

    // Add more code for receiving data, processing response, etc.

    return 0;
}
