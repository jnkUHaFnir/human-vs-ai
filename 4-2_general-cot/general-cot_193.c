#include <signal.h>

int findHost(struct addrinfo *servinfo[])
{
    puts("Searching for a server...");
    for (int i = 1; i < MAX_CONN; i++)   {
        mySock = socket(servinfo[0]->ai_family, 
                        servinfo[0]->ai_socktype, servinfo[0]->ai_protocol);
        if (mySock == -1) {
            sendErr("Socket() failed");
        }

        if (debug) {
            printf("Trying for 192.168.1.%d...\n", i);
        }

        signal(SIGALRM, exit_closedConn); // Set up the signal handler
        alarm(1);

        if (connect(mySock, servinfo[i]->ai_addr, servinfo[i]->ai_addrlen) != -1)  {
            alarm(0); // Cancel the alarm
            printf("Connected to 192.168.1.%d\n", i);
            return SUCCESS; // Connected successfully
        }

        close(mySock); // Close the socket if connection failed
    }

    return FAIL; // Connection not established within timeout
}
