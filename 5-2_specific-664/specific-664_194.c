int findHost(struct addrinfo *servinfo[])
{
    puts("Searching for a server...");

    // Create the socket outside the loop
    if ((mySock = socket(servinfo[0]->ai_family, servinfo[0]->ai_socktype, servinfo[0]->ai_protocol)) == -1)
        sendErr("Socket() failed");

    for (int i = 1; i < MAX_CONN; i++)   {
        if (debug) 
            printf("Trying for 192.168.1.%d...\n", i);

        // Set alarm after each connection attempt
        alarm(1);
        if (connect(mySock, servinfo[i]->ai_addr, servinfo[i]->ai_addrlen) != -1)  {
            alarm(OFF);
            printf("Connected to 192.168.1.%d\n", i);
            return SUCCESS;
        }
        // Close the socket if connection failed
        close(mySock);
    }

    // Close the socket if no connection was successful
    close(mySock);

    return FAIL;
}
