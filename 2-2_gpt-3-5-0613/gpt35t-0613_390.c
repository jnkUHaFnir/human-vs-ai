WSARecv(socketState->socket, &(socketState->wsaBuf), 1, NULL, &(socketState->flags), &(socketState->ovl), NULL);
WSABUF wsaBuf;
DWORD flags;
WSAOVERLAPPED ovl;
static void run(void)
{
    DWORD length;
    BOOL resultOk;
    WSAOVERLAPPED* ovl_res;
    SocketState* socketState;

    // Start the initial send operation
    sendBuffer();

    for (;;)
    {
        // Wait for completion of the send operation
        resultOk = get_completion_status(&length, &socketState, &ovl_res);
        if (!resultOk)
        {
            // Handle error
        }

        // Start the receive operation
        recvBuffer();

        // Start the next send operation
        sendBuffer();
    }
}
