void alarmHandler(int signal) {
    if (mySock != -1) {
        close(mySock);
        mySock = -1;
    }
}

int findHost(struct addrinfo *servinfo[])
{
    signal(SIGALRM, alarmHandler);

    puts("Searching for a server...");
    for (int i = 1; i < MAX_CONN; i++) {
        mySock = socket(servinfo[0]->ai_family, servinfo[0]->ai_socktype, servinfo[0]->ai_protocol);
        if (mySock == -1) {
            sendErr("Socket() failed");
        }

        if (debug)
            printf("Trying for 192.168.1.%d...\n", i);

        alarm(1);
        if (connect(mySock, servinfo[i]->ai_addr, servinfo[i]->ai_addrlen) != -1) {
            alarm(0);
            printf("Connected to 192.168.1.%d\n", i);
            return SUCCESS;
        }

        close(mySock);
        mySock = -1;
    }

    return FAIL;
}
