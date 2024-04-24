int findHost(struct addrinfo *servinfo[])
{
    puts("Searching for a server...");
    
    int alarmSet = 0;
    if (signal(SIGALRM, alarmHandler) == SIG_ERR) {
        sendErr("Signal handler registration failed");
    }

    for (int i = 1; i < MAX_CONN; i++)   {
        if ((mySock = socket(servinfo[0]->ai_family, 
                servinfo[0]->ai_socktype, servinfo[0]->ai_protocol)) == -1) {
            sendErr("Socket() failed");
        }
        
        if (debug) {
            printf("Trying for 192.168.1.%d...\n", i);
        }

        alarm(1);
        alarmSet = 1;

        if (connect(mySock, servinfo[i]->ai_addr, servinfo[i]->ai_addrlen) != -1)  {
            alarm(0); // Cancel the alarm
            alarmSet = 0;
            printf("Connected to 192.168.1.%d\n", i);
            return SUCCESS;
        }

        close(mySock);
    }

    if (alarmSet) {
        alarm(0); // Cancel the alarm if not yet invoked
    }

    return FAIL;
}

void alarmHandler(int sig) {
    // This can be left empty if you don't need to do anything specific with the alarm signal
}
