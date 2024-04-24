static DWORD WINAPI ClientWorkerThread(LPVOID lpParameter)
{
    HANDLE hCompletionPort = (HANDLE)lpParameter;
    DWORD dwBytesTransferred = 0;
    OVERLAPPED* pOverlapped;
    SocketState* lpSockState;

    while (TRUE)
    {
        BOOL bRet = GetQueuedCompletionStatus(hCompletionPort, &dwBytesTransferred, (PULONG_PTR)&lpSockState, &pOverlapped, INFINITE);
        
        if (!bRet)
        {
            // Handle error, break the loop or continue based on requirements
        }
        
        if (lpSockState->operation == OP_READ)
        {
            // Process received data here from lpSockState->buf
            // You can also post another WSARecv for continuous reading
        }
    }

    return 0;
}
