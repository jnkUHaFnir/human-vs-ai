#include <signal.h>

#define TIMEOUT_SECONDS 1

void timeoutHandler(int signal) {
    if (signal == SIGALRM) {
        close(mySock);
        alarm(0); // Reset the alarm
    }
}

int findHost(struct addrinfo *servinfo[]) {
    signal(SIGALRM, timeoutHandler);

    puts("Searching for a server...");
    for (int i = 1; i < MAX_CONN; i++) {
        if ((mySock = socket(servinfo[0]->ai_family, servinfo[0]->ai_socktype, servinfo[0]->ai_protocol)) == -1) {
            sendErr("Socket() failed");
        }
        
        if (debug) {
            printf("Trying for 192.168.1.%d...\n", i);
        }

        alarm(TIMEOUT_SECONDS); // Start the timer

        if (connect(mySock, servinfo[i]->ai_addr, servinfo[i]->ai_addrlen) != -1) {
            alarm(0); // Cancel the alarm
            printf("Connected to 192.168.1.%d\n", i);
            return SUCCESS;
        }

        close(mySock);
    }

    return FAIL;
}
