while (1) {
    client_len[socket_index] = sizeof(client_address[socket_index]);
    puts("waiting for client");
    client_sockfd[socket_index] = accept(
                           server_sockfd,
                           (struct sockaddr*)&client_address[socket_index],
                           &client_len[socket_index]
                           );
    if (client_sockfd[socket_index] < 0) {
        perror("Cannot accept connection\n");
        close(server_sockfd);
        exit(EXIT_FAILURE);
    }

    pthread_create( &threads[socket_index], NULL, forClient, (void*)client_sockfd[socket_index]);

    if(BUFSIZ == socket_index) {
        socket_index = 0;
    } else {
        ++socket_index;
    }

    // pthread_join(threads[socket_index], NULL); Remove this line
    
}
if (signal(SIGINT, sig_handler) == SIG_ERR)
    printf("\ncan't catch SIGINT\n");

// main loop...
void
sig_handler(int signo)
{
     if (signo == SIGINT){
             printf("!!  OUCH,  CTRL - C received  by server !!\n");
             shutdown(server_sockfd, SHUT_RDWR);
             g_running = 0;
     }
}
while ( g_running ) {
  // your accept code ...
  if (!g_running) break;
}
