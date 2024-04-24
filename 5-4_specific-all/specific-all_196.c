#include <signal.h>

int timedOut = 0;

void handleTimeout(int signal) {
    timedOut = 1;
}

int findHost(struct addrinfo *servinfo[])
{
    puts("Searching for a server...");
    struct sigaction sa;
    sa.sa_handler = handleTimeout;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);

    if (sigaction(SIGALRM, &sa, NULL) == -1) {
        sendErr("Sigaction failed");
    }

    for (int i = 1; i < MAX_CONN; i++) {
        if ((mySock = socket(servinfo[0]->ai_family,
                             servinfo[0]->ai_socktype, servinfo[0]->ai_protocol)) == -1) {
            sendErr("Socket() failed");
        }

        if (debug) {
            printf("Trying for 192.168.1.%d...\n", i);
        }

        timedOut = 0;
        alarm(1);

        if (connect(mySock, servinfo[i]->ai_addr, servinfo[i]->ai_addrlen) != -1) {
            alarm(0); // Cancel the alarm
            printf("Connected to 192.168.1.%d\n", i);
            return SUCCESS;
        }

        if (timedOut) {
            printf("Connection to 192.168.1.%d timed out\n", i);
            close(mySock);
            continue;
        }

        close(mySock);
    }

    return FAIL;
}
