#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFF_SIZE 1024

void close_connection(int socket) {
    close(socket);
    printf("Connection closed.\n");
}

int main() {
    // Your context and configuration initialization here

    int received;
    struct sockaddr_in server_addr;
    socklen_t addr_size = sizeof(struct sockaddr_in);

    /* socket */
    if ((context->socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1) {
        perror("Failed to create socket");
        exit(-1);
    }

    /* connect */
    if (connect(context->socket, (struct sockaddr *)&context->tx_addr, sizeof(struct sockaddr)) != 0) {
        perror("Couldn't connect to server");
        close_connection(context->socket);
        exit(-1);
    }

    /* create header */
    snprintf(context->packet, BUFF_SIZE,
             "GET %s HTTP/1.1\r\n" \
             "Host: %s\r\n\r\n", 
             conf->request, conf->host);

    /* send header */
    ssize_t sent = send(context->socket, context->packet, strlen(context->packet), 0);
    if (sent < 0) {
        perror("Failed to send");
        close_connection(context->socket);
        exit(-1);
    }

    /* receive response */
    while ((received = recv(context->socket, context->packet, BUFF_SIZE - 1, 0)) > 0) {
        context->packet[received] = '\0';
        printf("%s", context->packet);
    }

    if (received == 0) { // Reached end of data, connection is closed gracefully
        close_connection(context->socket);
    }
    else if (received < 0) {
        perror("Failed to receive");
        close_connection(context->socket);
        exit(-1);
    }

    return 0;
}
