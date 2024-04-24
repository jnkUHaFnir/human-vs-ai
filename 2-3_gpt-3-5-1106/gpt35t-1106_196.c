int findHost(struct addrinfo *servinfo[])
{
    puts("Searching for a server...");
    for (int i = 1; i < MAX_CONN; i++)   {
        if ((mySock = socket(servinfo[0]->ai_family, 
                servinfo[0]->ai_socktype, servinfo[0]->ai_protocol)) == -1)
            sendErr("Socket() failed");
        if (debug) 
            printf("Trying for 192.168.1.%d...\n", i);

        // Set the socket to non-blocking
        int flags = fcntl(mySock, F_GETFL, 0);
        fcntl(mySock, F_SETFL, flags | O_NONBLOCK);

        int result = connect(mySock, servinfo[i]->ai_addr, servinfo[i]->ai_addrlen);
        if (result == 0) {
            // Connected successfully
            fcntl(mySock, F_SETFL, flags);  // Set the socket back to blocking
            printf("Connected to 192.168.1.%d\n",i);
            return SUCCESS;
        } else {
            if (errno == EINPROGRESS) {
                // Connection is still in progress, handle it as needed
                // For example, you can use poll() or select() to wait for the connection to complete
                // ...
                // After the connection is successful, set the socket back to blocking
                fcntl(mySock, F_SETFL, flags);
                return SUCCESS;
            } else {
                // Error occurred, close the socket and continue the loop
                close(mySock);
            }
        }
    }
    return FAIL;
}
