#include <string.h>
#include <stdbool.h>

// Assuming buffer is defined as char buffer[256];

while(1) {
    if((n = read(newsocketfd, buffer, sizeof(buffer))) > 0) {
        buffer[n - 1] = '\0'; // Removing the newline character
        printf("(Message length %d) message from Client: %s\n", n, buffer);

        if(strcmp("q", buffer) == 0) {
            printf("Client is trying to close the connection %s\n", buffer);
            break; // Exit the loop when client sends "q"
        } else {
            printf("Received data from the client: %s\n", buffer);
        }

        if(write(newsocketfd, response, strlen(response)) > 0) {
            printf("Writing response to Client socket \n");
        } else {
            error("Error writing message \n");
        }
    } else {
        close(socketfd);
        close(newsocketfd);
        error("Error reading message \n");
    }
}

return EXIT_SUCCESS;
