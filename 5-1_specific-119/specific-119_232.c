// updated server.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <arpa/inet.h>
#include <fcntl.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

void* forClient(void* ptr);

int main(int argc, char **argv) {
    // Your existing code here

    signal(SIGINT, sig_handler); // Setup signal handler

    // Your existing code here

    pthread_t threads[MAX_CLIENTS];
    int socket_index = 0;

    while (1) {
        // Your existing code here

        pthread_create(&threads[socket_index], NULL, forClient, (void*)&client_sockfd[socket_index]);

        if(BUFSIZ == socket_index) {
            socket_index = 0;
        } else {
            ++socket_index;
        }
        // Move this line outside the loop
        // pthread_join(threads[socket_index], NULL);
    }
    return EXIT_SUCCESS;
}

void* forClient(void* ptr) {
    // Your existing code here

    int connect_socket = *((int*)ptr);
    // Don't pass client_sockfd, it's not necessary and may cause issues

    while (1) {
        // Your existing code here

        if (recv(connect_socket, receiveFileName, sizeof(receiveFileName), 0) <= 0) {
            break;
        }
        // Your existing code here
    }

    // Instead of passing &ret, use NULL
    pthread_exit(NULL);
}

void sig_handler(int signo) {
    if (signo == SIGINT) {
        printf("!!  OUCH,  CTRL - C received by server !!\n");
        // Properly handle SIGINT signal here
        // For example, you can set a flag to gracefully stop the server
    }
}
