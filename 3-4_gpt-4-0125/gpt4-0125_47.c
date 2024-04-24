int *client_sockfd_ptr = malloc(sizeof(int));
*client_sockfd_ptr = client_sockfd[socket_index];
pthread_create(&threads[socket_index], NULL, forClient, (void*)client_sockfd_ptr);
int connect_socket = *(int*)ptr;
free(ptr); // Don't forget to free the memory!
