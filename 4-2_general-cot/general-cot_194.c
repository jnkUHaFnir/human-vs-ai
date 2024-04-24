void handleAlarm(int sig) {
    // Handle the alarm signal here
    // For now, a simple print statement
    printf("Connection attempt timed out\n");
    close(mySock); // Close the socket when timed out
    exit(1); // Exit the program or handle the timeout accordingly
}
int findHost(struct addrinfo *servinfo[]) {
    puts("Searching for a server...");
    struct sigaction sa;
    sa.sa_handler = handleAlarm;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGALRM, &sa, NULL);

    for (int i = 1; i < MAX_CONN; i++) {
        if ((mySock = socket(servinfo[0]->ai_family, servinfo[0]->ai_socktype, servinfo[0]->ai_protocol)) == -1)
            sendErr("Socket() failed");
        if (debug)
            printf("Trying for 192.168.1.%d...\n", i);
        alarm(1);
        if (connect(mySock, servinfo[i]->ai_addr, servinfo[i]->ai_addrlen) == 0) {
            alarm(0); // Cancel the alarm if connection successful
            printf("Connected to 192.168.1.%d\n", i);
            return SUCCESS;
        }
        close(mySock);
    }

    return FAIL;
}
