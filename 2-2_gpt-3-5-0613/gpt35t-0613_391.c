
You need to replace the current `CreateIoCompletionPort` call with the above code.

2. In the `recvBuffer` and `sendBuffer` functions, you are using blocking socket functions (`recv` and `send`) instead of the overlapped I/O functions (`WSARecv` and `WSASend`). To make it work with IOCP, you should replace the `recv` and `send` calls with corresponding overlapped calls. Here's an example:

```csharp
// Replace the recvBuffer function
static void recvBuffer(void)
{
    DWORD bytesReceived;
    WSABUF wsaBuf;
    wsaBuf.buf = msgBuf;
    wsaBuf.len = BUFLEN;
    WSAOVERLAPPED overlapped;
    memset(&overlapped, 0, sizeof(WSAOVERLAPPED));
    overlapped.hEvent = NULL;

    if (WSARecv(sock, &wsaBuf, 1, &bytesReceived, 0, &overlapped, NULL) == SOCKET_ERROR)
    {
        int err = WSAGetLastError();
        if (err != ERROR_IO_PENDING)
        {
            printf("* error %d in WSARecv\n", err);
            exit(1);
        }
    }

    // Wait for the asynchronous operation to complete
    DWORD dwBytes;
    DWORD dwFlags;
    if (WSAGetOverlappedResult(sock, &overlapped, &dwBytes, TRUE, &dwFlags) == FALSE)
    {
        int err = WSAGetLastError();
        if (err != ERROR_IO_PENDING)
        {
            printf("* error %d in WSARecv\n", err);
            exit(1);
        }
    }
}

// Replace the sendBuffer function
static void sendBuffer(void)
{
    DWORD bytesSent;
    WSABUF wsaBuf;
    wsaBuf.buf = msgBuf;
    wsaBuf.len = strlen(msgBuf);
    WSAOVERLAPPED overlapped;
    memset(&overlapped, 0, sizeof(WSAOVERLAPPED));
    overlapped.hEvent = NULL;

    if (WSASend(sock, &wsaBuf, 1, &bytesSent, 0, &overlapped, NULL) == SOCKET_ERROR)
    {
        int err = WSAGetLastError();
        if (err != ERROR_IO_PENDING)
        {
            printf("* error %d in WSASend\n", err);
            exit(1);
        }
    }

    // Wait for the asynchronous operation to complete
    DWORD dwBytes;
    DWORD dwFlags;
    if (WSAGetOverlappedResult(sock, &overlapped, &dwBytes, TRUE, &dwFlags) == FALSE)
    {
        int err = WSAGetLastError();
        if (err != ERROR_IO_PENDING)
        {
            printf("* error %d in WSASend\n", err);
            exit(1);
        }
    }
}
