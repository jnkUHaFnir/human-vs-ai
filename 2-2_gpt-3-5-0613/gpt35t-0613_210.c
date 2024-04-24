static void recvBuffer(void)
{
    WSAOVERLAPPED ovl = {0};
    DWORD bytesReceived;
    DWORD flags = 0;

    printf("* receiving reply\n");

    if (WSARecv(sock, &sock_state.buf, 1, &bytesReceived, &flags, &ovl, NULL) == SOCKET_ERROR)
    {
        int err = WSAGetLastError();
        if (err != ERROR_IO_PENDING)
        {
            printf("* error %d in recv\n", err);
            exit(1);
        }
    }

    // Do not call recv() here.
    // The completion worker thread will handle the read completion.
}
static DWORD WINAPI ClientWorkerThread(LPVOID lpParameter)
{
    HANDLE hCompletionPort = (HANDLE)lpParameter;
    DWORD dwBytesTransferred;
    ULONG_PTR completionKey;
    LPOVERLAPPED pOverlapped;
    SocketState* socketState;

    while (TRUE)
    {
        BOOL bRet = GetQueuedCompletionStatus(hCompletionPort, &dwBytesTransferred, &completionKey, &pOverlapped, INFINITE);

        if (!bRet) {
            int err = GetLastError();
            printf("Error on completion: %d\n", err);
        }

        socketState = (SocketState*)completionKey;

        // Process completion based on socketState->operation (OP_READ or OP_WRITE)

        if (socketState->operation == OP_READ)
        {
            // Handle read completion
            // Example:
            printf("Received: %s\n", socketState->buf);

            // You can start another read operation using WSARecv here
        }
        else if (socketState->operation == OP_WRITE)
        {
            // Handle write completion
            // Example:
            printf("Sent: %s\n", socketState->buf);
        }
    }

    return 0;
}
for(;;)
{
    SocketState* socketState = new SocketState();
    socketState->socket = Socket;
    socketState->operation = OP_READ;
    WSAOVERLAPPED* pOverlapped = new WSAOVERLAPPED();
    pOverlapped->hEvent = NULL; // You can set an event if needed

    if (CreateIoCompletionPort((HANDLE)Socket, hCompletionPort, (ULONG_PTR)socketState, 0) != hCompletionPort)
    {
        int err = WSAGetLastError();
        printf("* error %d in CreateIoCompletionPort\n", err);
        exit(1);
    }

    if (WSARecv(Socket, &wsaBuf, 1, &dwReceivedBytes, &dwFlags, pOverlapped, NULL) == SOCKET_ERROR)
    {
        int err = WSAGetLastError();
        if (err != ERROR_IO_PENDING)
        {
            printf("* error %d in WSARecv\n", err);
            exit(1);
        }
    }

    Sleep(1000);
}
