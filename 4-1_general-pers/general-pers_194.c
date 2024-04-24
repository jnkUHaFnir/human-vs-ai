#include <signal.h>
#include <unistd.h>

#define TIMEOUT 1

int alarm_fired = 0;

void doNoth(int sig) {
    alarm_fired = 1;
}

int findHost(struct addrinfo *servinfo[]) {
    puts("Searching for a server...");

    struct sigaction sa;
    sa.sa_handler = doNoth;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGALRM, &sa, NULL);

    for (int i = 1; i < MAX_CONN; i++) {
        if ((mySock = socket(servinfo[0]->ai_family, 
                             servinfo[0]->ai_socktype, servinfo[0]->ai_protocol)) == -1) {
            sendErr("Socket() failed");
        }

        if (debug) {
            printf("Trying for 192.168.1.%d...\n", i);
        }

        alarm(TIMEOUT); // Set alarm for TIMEOUT seconds

        if (connect(mySock, servinfo[i]->ai_addr, servinfo[i]->ai_addrlen) != -1) {
            alarm(0); // Connection successful, disable the alarm
            printf("Connected to 192.168.1.%d\n", i);
            return SUCCESS;
        }

        if (alarm_fired) {
            // Alarm fired, timeout reached
            alarm_fired = 0; // Reset alarm flag
            close(mySock);
            continue; // Move on to the next host
        }

        close(mySock); // Close socket if connection failed
    }

    return FAIL;
}
