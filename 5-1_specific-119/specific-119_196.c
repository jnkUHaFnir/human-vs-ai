#include <signal.h>

#define TIMEOUT_SECONDS 1

// Signal handler function for SIGALRM
void alarmHandler(int signal) {
    // Do nothing
}

int findHost(struct addrinfo *servinfo[]) {
    signal(SIGALRM, alarmHandler);

    puts("Searching for a server...");
    for (int i = 1; i < MAX_CONN; i++) {
        int result;
        if ((mySock = socket(servinfo[0]->ai_family, 
                servinfo[0]->ai_socktype, servinfo[0]->ai_protocol)) == -1) {
            sendErr("Socket() failed");
        }
        
        if (debug) {
            printf("Trying for 192.168.1.%d...\n", i);
        }

        // Set an alarm for TIMEOUT_SECONDS
        alarm(TIMEOUT_SECONDS);

        result = connect(mySock, servinfo[i]->ai_addr, servinfo[i]->ai_addrlen);

        // Stop the alarm
        alarm(0);

        if (result != -1) {
            printf("Connected to 192.168.1.%d\n", i);
            //remove non-blocking
            return SUCCESS;
        }
        
        close(mySock);
    }
    return FAIL;
}
