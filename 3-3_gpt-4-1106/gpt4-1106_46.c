pthread_create(&threads[socket_index], NULL, forClient, (void*) &client_sockfd[socket_index]);

// Do not join here if you want to allow multiple clients to connect at the same time.
// pthread_join(threads[socket_index], NULL);

// Instead, you could detach the thread so that it cleans up after itself upon completion.
pthread_detach(threads[socket_index]);
pthread_create(&threads[socket_index], NULL, forClient, (void*)(intptr_t) client_sockfd[socket_index]);
void* forClient(void* ptr) {
    int connect_socket = (intptr_t) ptr;
    // ... rest of your code ...
}
while (1) {
    if (signal(SIGINT, sig_handler)) {
        break;
    }
    // ... rest of your code ...
}
if (signal(SIGINT, sig_handler) == SIG_ERR) {
    // Handle error here
}
