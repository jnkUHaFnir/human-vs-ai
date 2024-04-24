static void recvBuffer(void)
{
    memset(&sock_ovl, 0, sizeof(WSAOVERLAPPED));
    DWORD flags = 0;
    int bytesRead = 0;
    
    WSABUF wsabuf;
    wsabuf.buf = msgBuf;
    wsabuf.len = BUFLEN;

    printf("* receiving reply\n");

    if (WSARecv(sock, &wsabuf, 1, NULL, &flags, &sock_ovl, NULL) == SOCKET_ERROR)
    {
        int err = WSAGetLastError();
        if (err != WSA_IO_PENDING)
        {
            printf("* error %d in WSARecv\n", err);
            exit(1);
        }
    }

    DWORD bytesReceived;
    DWORD recvFlags = 0;
    if (!WSAGetOverlappedResult(sock, &sock_ovl, &bytesReceived, TRUE, &recvFlags))
    {
        int err = WSAGetLastError();
        printf("* error %d in WSAGetOverlappedResult\n", err);
        exit(1);
    }
}
