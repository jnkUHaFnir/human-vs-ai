#include <sys/time.h>
#include <sys/select.h>
#include <unistd.h>

#define TIMEOUT_SECONDS 1

int findHost(struct addrinfo *servinfo[]) {
    puts("Searching for a server...");
    
    struct timeval timeout;
    fd_set fdSet;
    int isConnected = 0;

    for (int i = 1; i < MAX_CONN; i++) {
        if ((mySock = socket(servinfo[0]->ai_family, servinfo[0]->ai_socktype, servinfo[0]->ai_protocol)) == -1) {
            sendErr("Socket() failed");
        }

        if (debug) {
            printf("Trying for 192.168.1.%d...\n", i);
        }
        
        // Set socket to non-blocking mode
        fcntl(mySock, F_SETFL, O_NONBLOCK);
        
        if (connect(mySock, servinfo[i]->ai_addr, servinfo[i]->ai_addrlen) == 0) {
            printf("Connected to 192.168.1.%d\n", i);
            isConnected = 1;
            break;
        } else if (errno == EINPROGRESS) {
            FD_ZERO(&fdSet);
            FD_SET(mySock, &fdSet);

            timeout.tv_sec = TIMEOUT_SECONDS;
            timeout.tv_usec = 0;

            int ready = select(mySock + 1, NULL, &fdSet, NULL, &timeout);

            if (ready == -1) {
                sendErr("Select() failed");
            } else if (ready == 0) {
                // Timeout reached
                close(mySock);
            } else {
                // Socket connected successfully
                isConnected = 1;
                break;
            }
        } else {
            close(mySock);
        }
    }

    if (isConnected) {
        return SUCCESS;
    } else {
        return FAIL;
    }
}
