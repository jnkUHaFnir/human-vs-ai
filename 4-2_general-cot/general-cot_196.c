#include <fcntl.h>

int setNonBlocking(int sockfd) {
    int flags = fcntl(sockfd, F_GETFL, 0);
    if (flags == -1) {
        return -1; // failed to get socket flags
    }
    if (fcntl(sockfd, F_SETFL, flags | O_NONBLOCK) == -1) {
        return -1; // failed to set non-blocking mode
    }
    return 0; // success
}

int findHost(struct addrinfo *servinfo[]) {
    puts("Searching for a server...");
    int connected = 0;
    int i = 1;

    for (; i < MAX_CONN; i++) {
        if ((mySock = socket(servinfo[0]->ai_family, 
                servinfo[0]->ai_socktype, servinfo[0]->ai_protocol)) == -1) {
            sendErr("Socket() failed");
        }

        if (setNonBlocking(mySock) == -1) {
            sendErr("Failed to set non-blocking mode");
        }

        if (debug) {
            printf("Trying for 192.168.1.%d...\n", i);
        }

        if (connect(mySock, servinfo[i]->ai_addr, servinfo[i]->ai_addrlen) == 0) {
            printf("Connected to 192.168.1.%d\n", i);
            connected = 1;
            break;
        }

        if (errno == EINPROGRESS) {
            struct pollfd pfd;
            pfd.fd = mySock;
            pfd.events = POLLOUT;

            if (poll(&pfd, 1, 1000) == 0) {
                close(mySock);
                continue;
            }

            int optval;
            socklen_t optlen = sizeof(optval);

            if (getsockopt(mySock, SOL_SOCKET, SO_ERROR, &optval, &optlen) == -1 || optval != 0) {
                close(mySock);
                continue;
            }

            printf("Connected to 192.168.1.%d\n", i);
            connected = 1;
            break;
        }

        close(mySock);
    }

    if (!connected) {
        return FAIL;
    }

    return SUCCESS;
}
