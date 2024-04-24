void handle_alarm(int signal) {
    // Do nothing
}

void prepare_signal_handling() {
    struct sigaction action;
    memset(&action, 0, sizeof(action));
    action.sa_handler = handle_alarm;
    sigaction(SIGALRM, &action, NULL);
}
int mySock;

if ((mySock = socket(servinfo[0]->ai_family, servinfo[0]->ai_socktype, servinfo[0]->ai_protocol)) == -1) {
    sendErr("Socket() failed");
}

for (int i = 1; i < MAX_CONN; i++)   {
    // ...    
    close(mySock);

    if (connect(mySock, servinfo[i]->ai_addr, servinfo[i]->ai_addrlen) != -1)  {
        // ...
    }
}
