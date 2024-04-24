static void run(void)
{
    DWORD length;
    BOOL resultOk;
    WSAOVERLAPPED* ovl_res;
    SocketState* socketState;

    for (;;)
    {
        resultOk = get_completion_status(&length, &socketState, &ovl_res);

        if (resultOk)
        {
            // Handle the received response
            recvBuffer();

            // Send new data
            sendBuffer();
        }
        else
        {
            // Handle error in getting completion status
        }
    }
}
