#include <fcntl.h>
#include <sys/select.h>

int setNonBlocking(int sock) {
    int flags = fcntl(sock, F_GETFL, 0);
    if (flags == -1) {
        perror("Error getting socket flags");
        return -1;
    }
    if (fcntl(sock, F_SETFL, flags | O_NONBLOCK) == -1) {
        perror("Error setting socket to non-blocking");
        return -1;
    }
    return 0;
}

int findHost(struct addrinfo *servinfo[]) {
    puts("Searching for a server...");
    
    int newSock;
    struct timeval timeout;
    fd_set fdSet;
    
    for (int i = 1; i < MAX_CONN; i++) {
        if ((newSock = socket(servinfo[0]->ai_family, servinfo[0]->ai_socktype, servinfo[0]->ai_protocol)) == -1) {
            sendErr("Socket() failed");
        }
        if (debug) {
            printf("Trying for 192.168.1.%d...\n", i);
        }
        
        // Set the socket to non-blocking
        if (setNonBlocking(newSock) == -1) {
            close(newSock);
            continue; // Move to the next iteration
        }
        
        if (connect(newSock, servinfo[i]->ai_addr, servinfo[i]->ai_addrlen) == -1) {
            if (errno == EINPROGRESS) {
                timeout.tv_sec = 1;
                timeout.tv_usec = 0;
                
                FD_ZERO(&fdSet);
                FD_SET(newSock, &fdSet);
                
                int selectStatus = select(newSock + 1, NULL, &fdSet, NULL, &timeout);
                if (selectStatus == 0) {
                    printf("Connection to 192.168.1.%d timed out\n", i);
                    close(newSock);
                    continue; // Move to the next iteration
                } else if (selectStatus == -1) {
                    perror("select() failed");
                    close(newSock);
                    continue; // Move to the next iteration
                }
            } else {
                perror("Connection failed");
                close(newSock);
                continue; // Move to the next iteration
            }
        }
        
        printf("Connected to 192.168.1.%d\n", i);
        return SUCCESS;
    }
    
    return FAIL;
}
