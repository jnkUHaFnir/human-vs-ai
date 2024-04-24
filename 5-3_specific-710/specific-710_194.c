#include <signal.h>

#define TIMEOUT 1 // Timeout in seconds

void alarmHandler(int signo) {
    // Handle the alarm signal, can be left empty for now
    // Or you can add some cleanup code here
}

int findHost(struct addrinfo *servinfo[]) {
    signal(SIGALRM, alarmHandler); // Register the signal handler
    puts("Searching for a server...");
    for (int i = 1; i < MAX_CONN; i++) {
        if ((mySock = socket(servinfo[0]->ai_family,
                             servinfo[0]->ai_socktype,
                             servinfo[0]->ai_protocol)) == -1) {
            sendErr("Socket() failed");
        }
        // Set the alarm to TIMEOUT seconds
        alarm(TIMEOUT);
        if (connect(mySock, servinfo[i]->ai_addr, servinfo[i]->ai_addrlen) != -1) {
            alarm(0); // Cancel the alarm
            printf("Connected to 192.168.1.%d\n", i);
            // Remove non-blocking
            return SUCCESS;
        }
        close(mySock);
    }
    alarm(0); // Cancel the alarm
    return FAIL;
}
