// Define an empty signal handler for the alarm signal
void alarmHandler(int signum) {
    // Do nothing
}
#include <signal.h>

// Signal handler function for alarm signal
void alarmHandler(int signum) {
    // Do nothing or handle as needed
}

int findHost(struct addrinfo *servinfo[]) {
    signal(SIGALRM, alarmHandler); // Set signal handler for SIGALRM

    puts("Searching for a server...");
    for (int i = 1; i < MAX_CONN; i++) {
        if ((mySock = socket(servinfo[0]->ai_family, 
            servinfo[0]->ai_socktype, servinfo[0]->ai_protocol)) == -1) {
            sendErr("Socket() failed");
        }

        if (debug) {
            printf("Trying for 192.168.1.%d...\n", i);
        }

        alarm(1); // Set alarm for 1 second
        if (connect(mySock, servinfo[i]->ai_addr, servinfo[i]->ai_addrlen) != -1) {
            alarm(0); // Reset the alarm as connection is successful
            printf("Connected to 192.168.1.%d\n", i);
            return SUCCESS;
        }

        close(mySock);
    }
    return FAIL;
}
