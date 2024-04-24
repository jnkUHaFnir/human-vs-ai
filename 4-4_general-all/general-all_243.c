#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main() {
    // Your socket setup code here...

    char buffer[256];
    char response[] = "Message received by the server";

    while(1){
        int n = read(newsocketfd, buffer, sizeof(buffer));
        if(n > 0) {
            buffer[n] = '\0'; // Ensure null-termination
            printf("(Message length %d) message from Client: %s\n", n, buffer);

            if(strcmp("q", buffer) == 0) {
                printf("Client is trying to close the connection: %s\n", buffer);
                break; // Exit the loop if client sends "q"
            } else {
                printf("Data received from the client: %s\n", buffer);
            }

            if(write(newsocketfd, response, strlen(response) + 1) <= 0){
                error("Error writing message \n");
            } else{
                printf("Writing response to Client socket\n");
            }
        } else {
            close(socketfd);
            close(newsocketfd);
            error("Error reading message \n");
        }
    }

    close(socketfd);
    close(newsocketfd);
    return EXIT_SUCCESS;
}
