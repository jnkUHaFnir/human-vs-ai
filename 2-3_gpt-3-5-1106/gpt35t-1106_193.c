int findHost(struct addrinfo *servinfo[])
{
    puts("Searching for a server...");

    if ((mySock = socket(servinfo[0]->ai_family, 
            servinfo[0]->ai_socktype, servinfo[0]->ai_protocol)) == -1)
        sendErr("Socket() failed");

    for (int i = 1; i < MAX_CONN; i++)   {
        if (debug) 
            printf("Trying for 192.168.1.%d...\n", i);
        
        // set socket to non-blocking
        int flags = fcntl(mySock, F_GETFL, 0);
        fcntl(mySock, F_SETFL, flags | O_NONBLOCK);

        if (connect(mySock, servinfo[i]->ai_addr, 
                    servinfo[i]->ai_addrlen) != -1)  {
            printf("Connected to 192.168.1.%d\n",i);
            // remove non-blocking and set to blocking for further operations
            // setsockopt(mySock, SOL_SOCKET, SO_NONBLOCK, 0, 0);
            return SUCCESS;
        } else {
            if (errno == EINPROGRESS) {
                // handle non-blocking operation in progress
                // continue with next iteration or wait for connection
            } else {
                // handle connection error
            }
        }
    }

    close(mySock);
    return FAIL;
}
