#include <fcntl.h>
#include <sys/time.h>

...

int findHost(struct addrinfo *servinfo[])
{
    puts("Searching for a server...");
    struct timeval timeout;
    timeout.tv_sec = 1;  // Set timeout to 1 second
    timeout.tv_usec = 0;

    int sockfd;
    for (int i = 1; i < MAX_CONN; i++) {
        if ((sockfd = socket(servinfo[0]->ai_family, 
                servinfo[0]->ai_socktype, servinfo[0]->ai_protocol)) == -1) {
            sendErr("Socket() failed");
        }
        if (debug) {
            printf("Trying for 192.168.1.%d...\n", i);
        }

        // Set socket to non-blocking
        if (fcntl(sockfd, F_SETFL, fcntl(sockfd, F_GETFL, 0) | O_NONBLOCK) == -1) {
            sendErr("Setting socket to non-blocking failed");
        }

        if (connect(sockfd, servinfo[i]->ai_addr, servinfo[i]->ai_addrlen) == -1) {
            // Check if error is EINPROGRESS (operation is now in progress)
            if (errno == EINPROGRESS) {
                fd_set write_fds;
                FD_ZERO(&write_fds);
                FD_SET(sockfd, &write_fds);

                int result = select(sockfd + 1, NULL, &write_fds, NULL, &timeout);
                if (result == 0) {
                    printf("Connection timeout to 192.168.1.%d\n", i);
                    close(sockfd);
                    continue;
                } else if (result < 0) {
                    sendErr("Select failed");
                }
            } else {
                sendErr("Connection failed");
            }
        }

        printf("Connected to 192.168.1.%d\n", i);
        // Remove non-blocking
        fcntl(sockfd, F_SETFL, fcntl(sockfd, F_GETFL, 0) & ~O_NONBLOCK);
        return SUCCESS;
    }
    
    return FAIL;
}
