#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <signal.h>
#include <pthread.h>

#define MAX_CLIENTS 100

int client_sockets[MAX_CLIENTS];
int total_clients = 0;
pthread_mutex_t lock;
int close_server = 0;

void *handle_client(void *t)
{
    int client_socket = *((int *)t);
    char buffer[256];

    while (1)
    {
        memset(buffer, 0, sizeof(buffer));
        ssize_t n = read(client_socket, buffer, 255);

        if(n <= 0 || close_server)
        {
            break;
        }

        printf("Client sent: %s\n", buffer);

        char *msg = "Message received";
        write(client_socket, msg, strlen(msg));
    }

    close(client_socket);
    pthread_exit(NULL);
}

void handle_sigint(int sig)
{
    printf("Caught signal %d\n", sig);

    for(int i = 0; i < total_clients; i++)
        close(client_sockets[i]);

    close_server = 1;
}

int main(int argc, const char *argv[])
{
    signal(SIGINT, handle_sigint);

    int server_socket, client_socket;
    struct sockaddr_in serv_addr, client_addr;
    pthread_t threads[MAX_CLIENTS];

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(5000);
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (bind(server_socket, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("Error binding socket\n");
        return 1;
    }

    if(listen(server_socket, 5) < 0)
    {
        printf("Error listening\n");
        return 1;
    }

    int i = 0;
    while(1)
    {
        int len = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &len);
        pthread_mutex_lock(&lock);

        if(i < MAX_CLIENTS)
        {
            client_sockets[i] = client_socket;
            total_clients++;
            int err = pthread_create(&threads[i], NULL, handle_client, &client_socket);
            if(err)
            {
                printf("Error creating thread\n");
                return 1;
            }
        }

        if(close_server)
            break;

        i++;
        pthread_mutex_unlock(&lock);
     }

     pthread_mutex_destroy(&lock);
     return 0;
}
