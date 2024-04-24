// Adjust buffer sizes
char lpOutputBuf[1024];
int outBufLen = 1024;
DWORD dwBytes;
OVERLAPPED over;
SOCKET newSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
sockaddr_in local, remote;
int localLen = sizeof(sockaddr_in), remoteLen = sizeof(sockaddr_in);

while (true) {
    memset(&over, 0, sizeof(over));
    if (AcceptEx(AcceptorSock, newSock, lpOutputBuf, 0, sizeof(sockaddr_in) + 16, sizeof(sockaddr_in) + 16, &dwBytes, &over) == FALSE) {
        int x = WSAGetLastError();
        if (x != ERROR_IO_PENDING) {
            ErrorAbort("Could not acceptex a new connection");
        }
    } else {
        // The buffer sizes for local and remote addresses
        LPFN_GETACCEPTEXSOCKADDRS lpfnGetAcceptExSockaddrs = NULL;
        if (!GetAcceptExSockaddrs) {
            GUID GuidAcceptEx = WSAID_GETACCEPTEXSOCKADDRS;
            DWORD dwBytes = 0;
            WSAIoctl(AcceptorSock, SIO_GET_EXTENSION_FUNCTION_POINTER, &GuidAcceptEx, sizeof(GuidAcceptEx), &lpfnGetAcceptExSockaddrs, sizeof(lpfnGetAcceptExSockaddrs), &dwBytes, NULL, NULL);
        }

        // Process lpOutputBuf to get local and remote addresses
        lpfnGetAcceptExSockaddrs(lpOutputBuf, 0, sizeof(sockaddr_in) + 16, sizeof(sockaddr_in) + 16, (LPSOCKADDR*) &local, &localLen, (LPSOCKADDR*) &remote, &remoteLen);
        // Now you can use local and remote sockaddr_in structures to get the addresses
    }
}
