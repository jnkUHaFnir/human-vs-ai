static void sendBuffer(void)
{
    WSABUF wsabuf;
    DWORD bytesSent = 0;
    SOCKET_STATE* socketState = &sock_state;
    WSAOVERLAPPED* ovl = &socketState->ovl;

    // Initialize necessary structures
    memset(&ovl, 0, sizeof(WSAOVERLAPPED));

    // Prepare data to be sent
    char message[] = "Hello from client!";
    wsabuf.buf = message;
    wsabuf.len = strlen(message);

    // Perform asynchronous send operation
    if (WSASend(sock, &wsabuf, 1, NULL, 0, ovl, NULL) == SOCKET_ERROR) {
        int err = WSAGetLastError();
        if (err != WSA_IO_PENDING) {
            printf("* error %d in WSASend\n", err);
            exit(1);
        }
    }
}

// -----------------------------------------------------------------------------

static void run(void)
{
    DWORD sentLength;
    DWORD flags = 0;
    BOOL resultOk;
    WSAOVERLAPPED* ovl_res;
    SocketState* socketState;

    sendBuffer(); // Start the first send operation

    for (;;) {
        resultOk = get_completion_status(&sentLength, &socketState, &ovl_res);

        if (resultOk) {
            // Check for the operation completed
            if (socketState->operation == OP_WRITE) {
                recvBuffer(); // Initiates receiving data after each send completes
            }
        }
    }
}
