#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>

// Function to find the host with a timeout
int findHost(struct addrinfo *servinfo[])
{
    puts("Searching for a server...");
    struct timeval timeout = {1, 0}; // Set timeout to 1 second
    fd_set writefds;
    
    for (int i = 1; i < MAX_CONN; i++)
    {
        mySock = socket(servinfo[0]->ai_family, servinfo[0]->ai_socktype, servinfo[0]->ai_protocol);
        if (mySock == -1)
        {
            sendErr("Socket() failed");
            continue;
        }

        if (debug)
            printf("Trying for 192.168.1.%d...\n", i);

        FD_ZERO(&writefds);
        FD_SET(mySock, &writefds);

        // Using select to set timeout for connection attempt
        if (select(mySock + 1, NULL, &writefds, NULL, &timeout) == 1)
        {
            if (connect(mySock, servinfo[i]->ai_addr, servinfo[i]->ai_addrlen) != -1)
            {
                printf("Connected to 192.168.1.%d\n", i);
                return SUCCESS; // Successful connection
            }
        }
        // Close the socket if not connected within the timeout
        close(mySock);
    }

    return FAIL; // No successful connection found
}
