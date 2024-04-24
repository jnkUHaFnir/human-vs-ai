fcntl(mySock, F_SETFL, O_NONBLOCK);
fd_set writeSet;
FD_ZERO(&writeSet);
FD_SET(mySock, &writeSet);

struct timeval timeout;
timeout.tv_sec = 1;
timeout.tv_usec = 0;

int ready = select(mySock + 1, NULL, &writeSet, NULL, &timeout);
if (ready == -1) {
    sendErr("Select() failed");
} else if (ready == 0) {
    // Timeout occurred
    close(mySock);
    return FAIL;
}
int connectStatus;
socklen_t connectLen = sizeof(connectStatus);
getsockopt(mySock, SOL_SOCKET, SO_ERROR, &connectStatus, &connectLen);

if (connectStatus != 0) {
    // Connection failed
    close(mySock);
    return FAIL;
}
