#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>

int makeNonBlocking(int fd) {
    int flags = fcntl(fd, F_GETFL, 0);
    if (flags == -1) {
        perror("fcntl(F_GETFL)");
        return -1;
    }

    flags |= O_NONBLOCK;
    if (fcntl(fd, F_SETFL, flags) == -1) {
        perror("fcntl(F_SETFL)");
        return -1;
    }

    return 0;
}

int findHost(struct addrinfo *servinfo[])
{
    puts("Searching for a server...");

    int connectStatus;
    int socketIndex = 1;

    while (socketIndex < MAX_CONN) {
        mySock = socket(servinfo[0]->ai_family, servinfo[0]->ai_socktype, servinfo[0]->ai_protocol);
        if (mySock == -1) {
            perror("Socket() failed");
            return FAIL;
        }

        if (makeNonBlocking(mySock) == -1) {
            close(mySock);
            return FAIL;
        }

        connectStatus = connect(mySock, servinfo[socketIndex]->ai_addr, servinfo[socketIndex]->ai_addrlen);
        if (connectStatus == -1 && errno != EINPROGRESS) {
            perror("Connect() failed");
            close(mySock);
            return FAIL;
        }

        struct pollfd pfd;
        pfd.fd = mySock;
        pfd.events = POLLOUT;

        int pollStatus = poll(&pfd, 1, 1000);  // 1 second timeout
        if (pollStatus == -1) {
            perror("Poll() failed");
            close(mySock);
            return FAIL;
        } else if (pollStatus == 0) {
            printf("Timed out trying to connect to 192.168.1.%d\n", socketIndex);
            close(mySock);
            socketIndex++;
            continue;
        }

        if (pfd.revents & POLLOUT) {
            printf("Connected to 192.168.1.%d\n", socketIndex);
            return SUCCESS;
        }

        printf("Connect() failed for 192.168.1.%d\n", socketIndex);
        close(mySock);
        socketIndex++;
    }

    return FAIL;
}
