#include <signal.h>

int findHost(struct addrinfo *servinfo[])
{
    int status = FAIL;
    struct sigaction sa;

   

    sa.sa_handler = exit_closedConn;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGALRM, &sa, NULL) == -1)
        sendErr("Sigaction failed");

    puts("Searching for a server...");
    for (int i = 1; i < MAX_CONN; i++)   {
        if ((mySock = socket(servinfo[0]->ai_family, 
                servinfo[0]->ai_socktype, servinfo[0]->ai_protocol)) == -1) {
            sendErr("Socket() failed");
            continue; // Move to the next iteration
        }

        if (debug) 
            printf("Trying for 192.168.1.%d...\n", i);

        alarm(1);
        if (connect(mySock, servinfo[i]->ai_addr, servinfo[i]->ai_addrlen) != -1)  {
            alarm(OFF);
            printf("Connected to 192.168.1.%d\n", i);
            status = SUCCESS;
            break;
        } else {
            close(mySock); // Close the socket if the connection attempt fails
        }
    }

    return status;
}
