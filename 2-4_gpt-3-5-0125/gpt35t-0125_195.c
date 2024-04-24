int findHost(struct addrinfo *servinfo[])
{
    puts("Searching for a server...");
    int connected = 0; // flag to track if a successful connection is made

    // create the socket outside the loop
    mySock = socket(servinfo[0]->ai_family, servinfo[0]->ai_socktype, servinfo[0]->ai_protocol);
    if (mySock == -1) {
        sendErr("Socket() failed");
    }

    for (int i = 1; i < MAX_CONN && !connected; i++) {
        if (debug) {
            printf("Trying for 192.168.1.%d...\n", i);
        }

        alarm(1);
        if (connect(mySock, servinfo[i]->ai_addr, servinfo[i]->ai_addrlen) != -1) {
            alarm(0); // cancel the alarm because connection succeeded
            printf("Connected to 192.168.1.%d\n", i);
            connected = 1;
        } else {
            close(mySock); // close the socket if connection failed
        }
    }

    if (!connected) {
        sendErr("No hosts found");
    }

    return SUCCESS;
}
