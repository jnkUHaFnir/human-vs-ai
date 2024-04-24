static void sendBuffer(void)
{
    DWORD flags = 0;
    WSABUF wsabuf;
    int pendingLen = BUFLEN;
    
    printf("* sending message\n");
    sprintf(msgBuf, "%05 *****", msgNumber++);

    wsabuf.buf = msgBuf;
    wsabuf.len = (ULONG)strlen(msgBuf);

    if (WSASend(sock, &wsabuf, 1, NULL, flags, &sock_ovl, NULL) == SOCKET_ERROR)
    {
        int err = WSAGetLastError();
        if (err != WSA_IO_PENDING)
        {
            printf("* error %d in WSASend\n", err);
            exit(1);
        }
    }
}
