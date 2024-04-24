static void recvBuffer(void)
{
    printf("* receiving reply\n");

    WSABUF DataBuf;
    DataBuf.buf = msgBuf;
    DataBuf.len = BUFLEN;

    DWORD flags = 0;
    DWORD bytesReceived = 0;
    WSAOVERLAPPED overlapped;
    SecureZeroMemory(&overlapped, sizeof(WSAOVERLAPPED));
    overlapped.hEvent = WSACreateEvent();

    int result = WSARecv(sock, &DataBuf, 1, &bytesReceived, &flags, &overlapped, NULL);

    if (result == SOCKET_ERROR) {
        int err = WSAGetLastError();
        if (err != WSA_IO_PENDING) {
            printf("* error %d in WSARecv\n", err);
            exit(1);
        }
    }

    // You should handle the completion of the operation in the completion port worker threads
}
