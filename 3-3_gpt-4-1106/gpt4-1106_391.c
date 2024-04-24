// ClientWorkerThread should take a HANDLE to the IOCP.
static DWORD WINAPI ClientWorkerThread(LPVOID lpParameter)
{
    HANDLE hCompletionPort = (HANDLE)lpParameter;
    DWORD dwBytesTransferred = 0;
    ULONG_PTR completionKey = 0;
    OVERLAPPED *pOverlapped = NULL;

    while (TRUE)
    {
        BOOL bRet = GetQueuedCompletionStatus(hCompletionPort, &dwBytesTransferred, &completionKey, &pOverlapped, INFINITE);
        if (!bRet)
        {
            // Handle error.
            continue;
        }

        if (dwBytesTransferred == 0)
        {
            // Graceful close
            continue;
        }

        // Completion key is typically a pointer to your per-socket or per-IO structure.
        // Process the completed IO operation here, either read or write based on your structure's data.
    }

    return 0;
}
// Where you have initialized the connection and associated the socket with the IOCP.
WSAOVERLAPPED overlapped = { 0 };
SocketState *clientState; // You need to allocate memory for this and initialize.
clientState->operation = OP_READ;
WSABUF wsaBuf;
wsaBuf.buf = clientState->buffer; // buffer is part of your SocketState
wsaBuf.len = sizeof(clientState->buffer);
DWORD flags = 0;

// Begin to receive.
int iResult = WSARecv(Socket, &wsaBuf, 1, NULL, &flags, &overlapped, NULL);
if (iResult == SOCKET_ERROR && WSAGetLastError() != WSA_IO_PENDING)
{
    // Handle error.
}
