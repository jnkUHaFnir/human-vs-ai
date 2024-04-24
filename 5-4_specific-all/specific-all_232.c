
2. **Signal handling**:
   - Ensure that the signal handler is properly registered using `signal` function and handle the termination logic in the handler function.
   - To handle SIGINT in the server and client, you can set up a signal handler that properly closes sockets and terminates the program.
  
Here is an example of how you can set up a signal handler in both server and client:
   ```c
   void sigintHandler(int sig) {
       printf("Ctrl-C caught, exiting...\n");
       // Close any open sockets or perform cleanup before exiting
       // Close server socket
       close(server_sockfd);

       // Close client sockets
       for (int i = 0; i < BUFSIZ; i++) {
           close(client_sockfd[i]);
       }

       exit(EXIT_SUCCESS);
   }

   // Register the signal handler
   signal(SIGINT, sigintHandler);
   ```

By making these modifications, you should be able to handle multiple client connections efficiently and ensure proper termination of the server and client programs when SIGINT (Ctrl-C) signal is caught.
