// Initialize newSock socket
newSock = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, WSA_FLAG_OVERLAPPED);
if (newSock == INVALID_SOCKET) {
    ErrorAbort("Could not create new socket for AcceptEx");
}

// Call AcceptEx
if (AcceptEx(AcceptorSock, newSock, lpOutputBuf, outBufLen - ((sizeof(sockaddr_in) + 16) * 2), sizeof(sockaddr_in) + 16, sizeof(sockaddr_in) + 16, &dwBytes, &over) == FALSE) {
    int x = WSAGetLastError();
    if (x != WSA_IO_PENDING) {
        ErrorAbort("Could not acceptex a new connection");
    }
}
