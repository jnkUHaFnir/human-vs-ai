// Before creating a thread
int *client_sock_ptr = malloc(sizeof(int));
*client_sock_ptr = client_sockfd[socket_index];
pthread_create(&threads[socket_index], NULL, forClient, client_sock_ptr);

// Remove `pthread_join` here, or manage threads differently (e.g., detach them right after creation).
void* forClient(void* ptr) {
    int connect_socket = *(int*) ptr;
    free(ptr); // Free the dynamically allocated memory.
    ...
}
