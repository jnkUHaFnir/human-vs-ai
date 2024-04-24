static void run(void)
{
    DWORD length;
    BOOL resultOk;
    WSAOVERLAPPED* ovl_res;
    SocketState* socketState;

    for (;;)
    {
        sendBuffer();

        // Wait for the send completion
        resultOk = get_completion_status(&length, &socketState, &ovl_res);
        if (!resultOk)
        {
            // Handle error if needed
            exit(1);
        }

        recvBuffer();
    }
}
