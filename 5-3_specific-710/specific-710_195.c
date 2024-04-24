#include <signal.h> // Include for signal handling

#define CONNECT_TIMEOUT 1

volatile sig_atomic_t timed_out = 0;

// Signal handler for alarm
void handleAlarm(int signal) {
    timed_out = 1;
}

int findHost(struct addrinfo *servinfo[]) {
    struct sigaction sa;
    sa.sa_handler = handleAlarm;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGALRM, &sa, NULL);

    puts("Searching for a server...");
    for (int i = 1; i < MAX_CONN; i++) {
        if ((mySock = socket(servinfo[0]->ai_family, 
                servinfo[0]->ai_socktype, servinfo[0]->ai_protocol)) == -1)
            sendErr("Socket() failed");

        if (debug) 
            printf("Trying for 192.168.1.%d...\n", i);

        // Set alarm for timeout
        timed_out = 0;
        alarm(CONNECT_TIMEOUT);

        if (connect(mySock, servinfo[i]->ai_addr, servinfo[i]->ai_addrlen) != -1) {
            alarm(0); // Cancel the alarm
            printf("Connected to 192.168.1.%d\n", i);
            return SUCCESS;
        }

        if (timed_out) {
            printf("Connection attempt to 192.168.1.%d timed out\n", i);
            close(mySock);
            timed_out = 0;
        }
    }
    return FAIL;
}
