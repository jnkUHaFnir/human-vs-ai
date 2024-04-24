#include <signal.h>

volatile sig_atomic_t timeout_flag = 0;

void alarm_handler(int signum) {
    timeout_flag = 1;
}

int findHost(struct addrinfo *servinfo[]) {
    struct sigaction sa;
    sa.sa_handler = alarm_handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGALRM, &sa, NULL); // Set up the signal handler for SIGALRM

    puts("Searching for a server...");
    for (int i = 1; i < MAX_CONN; i++) {
        if ((mySock = socket(servinfo[0]->ai_family,
                             servinfo[0]->ai_socktype,
                             servinfo[0]->ai_protocol)) == -1) {
            sendErr("Socket() failed");
        }

        if (debug)
            printf("Trying for 192.168.1.%d...\n", i);

        timeout_flag = 0;
        alarm(1); // Set the alarm for 1 second

        if (connect(mySock, servinfo[i]->ai_addr, servinfo[i]->ai_addrlen) != -1) {
            alarm(0); // Cancel the alarm
            printf("Connected to 192.168.1.%d\n", i);
            return SUCCESS;
        } else if (timeout_flag) {
            alarm(0); // Cancel the alarm
            close(mySock); // Close the socket if timed out
        }
    }

    return FAIL;
}
