void alarmHandler(int sig) {
    printf("Connection attempt timed out. Moving on to the next host.\n");
    close(mySock);
}

int findHost(struct addrinfo *servinfo[])
{
    signal(SIGALRM, alarmHandler);

    puts("Searching for a server...");
    for (int i = 1; i < MAX_CONN; i++) {
        if ((mySock = socket(servinfo[0]->ai_family,
                             servinfo[0]->ai_socktype, servinfo[0]->ai_protocol)) == -1)
            sendErr("Socket() failed");

        if (debug)
            printf("Trying for 192.168.1.%d...\n", i);

        alarm(1); // Set alarm for 1 second

        if (connect(mySock, servinfo[i]->ai_addr, servinfo[i]->ai_addrlen) != -1) {
            alarm(0); // Cancel the alarm
            printf("Connected to 192.168.1.%d\n", i);
            return SUCCESS;
        }

        close(mySock);
    }

    return FAIL;
}
