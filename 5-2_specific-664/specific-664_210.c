static void recvBuffer(void)
{
    DWORD flags = 0;
    WSABUF dataBuf;
    dataBuf.len = BUFLEN;
    dataBuf.buf = msgBuf;

    printf("* receiving reply\n");

    OVERLAPPED overlapped;
    memset(&overlapped, 0, sizeof(OVERLAPPED));

    DWORD bytesReceived = 0;
    int result = WSARecv(sock, &dataBuf, 1, &bytesReceived, &flags, &overlapped, NULL);

    if (result == SOCKET_ERROR)
    {
        int err = WSAGetLastError();
        if (err != WSA_IO_PENDING)
        {
            printf("* error %d in WSARecv\n", err);
            exit(1);
        }
    }
}
