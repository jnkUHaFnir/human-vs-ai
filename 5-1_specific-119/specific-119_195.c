#include <fcntl.h>

int alarmFlag = 0;

void alarmHandler(int signal) {
    alarmFlag = 1;
}

int findHost(struct addrinfo *servinfo[]) {
    struct sigaction sa;
    sa.sa_handler = alarmHandler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGALRM, &sa, NULL) == -1) {
        sendErr("Sigaction failed");
    }

    puts("Searching for a server...");
    for (int i = 1; i < MAX_CONN; i++)   {
        if (connect(mySock, servinfo[i]->ai_addr, servinfo[i]->ai_addrlen) != -1)  {
            printf("Connected to 192.168.1.%d\n", i);
            return SUCCESS;
        }

        alarmFlag = 0;
        alarm(1);
        while (!alarmFlag) {
            // Handle non-blocking socket connecting here
        }
        alarm(0);

        if (alarmFlag) {
            printf("Timeout connecting to 192.168.1.%d\n", i);
            // Add timeout handling if needed
        }
    }
    return FAIL;
}
