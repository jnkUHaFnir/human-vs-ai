#include <signal.h>

volatile sig_atomic_t alarm_fired = 0;

void alarm_handler(int sig) {
    alarm_fired = 1;
}

int findHost(struct addrinfo *servinfo[]) {
    struct sigaction sa;
    sa.sa_handler = alarm_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGALRM, &sa, NULL) == -1) {
        sendErr("Sigaction failed");
    }

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
            alarm(0); // Cancel the alarm
            printf("Connected to 192.168.1.%d\n", i);
            return SUCCESS;
        }

        if (alarm_fired) {
            close(mySock); // Close the socket if alarm fired
            alarm_fired = 0; // Reset alarm flag
        }
    }
    return FAIL;
}
