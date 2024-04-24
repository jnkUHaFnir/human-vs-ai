int findHost(struct addrinfo *servinfo[])
{
    puts("Searching for a server...");
    struct sockaddr_storage addr;
    socklen_t addr_len;
    int connected = 0;

    if ((mySock = socket(servinfo[0]->ai_family,
                         servinfo[0]->ai_socktype,
                         servinfo[0]->ai_protocol)) == -1) {
        sendErr("Socket() failed");
    }

    for (int i = 1; i < MAX_CONN; i++) {
        if (debug)
            printf("Trying for 192.168.1.%d...\n", i);

        // Set socket to non-blocking mode
        int flags = fcntl(mySock, F_GETFL, 0);
        fcntl(mySock, F_SETFL, flags | O_NONBLOCK);

        // Update address information for new connection attempt
        memcpy(&addr, servinfo[i]->ai_addr, servinfo[i]->ai_addrlen);
        addr_len = servinfo[i]->ai_addrlen;

        // Try to connect with a timeout
        if (connect(mySock, (struct sockaddr*)&addr, addr_len) == 0) {
            connected = 1;
            printf("Connected to 192.168.1.%d\n", i);
            break;
        } else if (errno == EINPROGRESS) {
            // Use select or poll to wait for the connection with a timeout
            int ret;
            fd_set write_set;
            struct timeval timeout;

            FD_ZERO(&write_set);
            FD_SET(mySock, &write_set);

            timeout.tv_sec = 1;
            timeout.tv_usec = 0;

            ret = select(mySock + 1, NULL, &write_set, NULL, &timeout);
            
            if (ret > 0 && FD_ISSET(mySock, &write_set)) {
                // Connection successful
                connected = 1;
                printf("Connected to 192.168.1.%d\n", i);
                break;
            } else if (ret == 0) {
                // Timeout reached
                close(mySock);
                continue;
            }
        }

        // Connection failed or timed out, close socket and try next host
        close(mySock);
    }
    
    if (!connected) {
        sendErr("No hosts found");
    }

    // Set socket back to blocking mode
    int flags = fcntl(mySock, F_GETFL, 0);
    fcntl(mySock, F_SETFL, flags & ~O_NONBLOCK);

    return SUCCESS;
}
