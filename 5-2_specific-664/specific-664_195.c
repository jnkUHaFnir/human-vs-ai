#include <signal.h>

void timeoutHandler(int sig) {
    // Do nothing, just catch the signal
}

int findHost(struct addrinfo *servinfo[]) {
    puts("Searching for a server...");
    
    struct sigaction sa;
    sa.sa_handler = timeoutHandler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    
    if (sigaction(SIGALRM, &sa, NULL) == -1) {
        sendErr("Sigaction failed");
    }

    for (int i = 1; i < MAX_CONN; i++) {
        if ((mySock = socket(servinfo[0]->ai_family,
                             servinfo[0]->ai_socktype,
                             servinfo[0]->ai_protocol)) == -1) {
            sendErr("Socket() failed");
        }

        if (debug) {
            printf("Trying for 192.168.1.%d...\n", i);
        }
        
        alarm(1); // Set an alarm for 1 second
        
        if (connect(mySock, servinfo[i]->ai_addr, servinfo[i]->ai_addrlen) != -1) {
            alarm(0); // Cancel the alarm
            printf("Connected to 192.168.1.%d\n", i);
            return SUCCESS;
        }
        
        // Close the socket in case of timeout
        close(mySock);
    }

    return FAIL;
}
