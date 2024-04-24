// After connecting the socket and associating it with the IOCP...
WSABUF wsaBuf;
char buffer[1000];
wsaBuf.buf = buffer;
wsaBuf.len = sizeof(buffer);

DWORD dwReceivedBytes = 0;
DWORD dwFlags = 0;
WSAOVERLAPPED wsaOverlapped;
ZeroMemory(&wsaOverlapped, sizeof(wsaOverlapped));

// Issue the initial WSARecv request.
int iResult = WSARecv(Socket, &wsaBuf, 1, &dwReceivedBytes, &dwFlags, &wsaOverlapped, NULL);
if (iResult == SOCKET_ERROR && WSAGetLastError() != ERROR_IO_PENDING) {
    // Handle error...
}
static DWORD WINAPI ClientWorkerThread(LPVOID lpParameter) {
    HANDLE hCompletionPort = (HANDLE)lpParameter;
    DWORD dwBytesTransferred = 0;
    ULONG_PTR completionKey;
    WSAOVERLAPPED* pOverlapped;

    while (TRUE) {
        BOOL bRet = GetQueuedCompletionStatus(
            hCompletionPort, 
            &dwBytesTransferred,
            &completionKey,
            (LPOVERLAPPED*)&pOverlapped, 
            INFINITE
        );

        if (bRet) {
            // Completion packet received.
            // Use dwBytesTransferred and pOverlapped as needed.
        } else {
            // An error occurred. Call GetLastError() for more information.
        }
    }

    return 0;
}
