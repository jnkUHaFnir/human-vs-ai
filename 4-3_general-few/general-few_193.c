int findHost(struct addrinfo *servinfo[])
{
    puts("Searching for a server...");
    
    signal(SIGALRM, exit_alarm); // Set up the signal handler

    // Set the alarm before the loop
    alarm(1);

    for (int i = 1; i < MAX_CONN; i++)   {
        if ((mySock = socket(servinfo[0]->ai_family, 
                servinfo[0]->ai_socktype, servinfo[0]->ai_protocol)) == -1)
            sendErr("Socket() failed");
        if (debug) 
            printf("Trying for 192.168.1.%d...\n", i);

        if (connect(mySock, servinfo[i]->ai_addr, servinfo[i]->ai_addrlen) != -1)  {
            alarm(0); // Cancel the alarm
            printf("Connected to 192.168.1.%d\n", i);
            return SUCCESS;
        }
        close(mySock);
    }
    
    return FAIL;
}

void exit_alarm(int sig)
{
    printf("Connection attempt timed out\n");
    close(mySock);
    exit(EXIT_FAILURE);
}
