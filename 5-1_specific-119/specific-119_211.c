static void run(void)
{
    DWORD length;
    BOOL resultOk;
    WSAOVERLAPPED* ovl_res;
    SocketState* socketState;

    for (;;)
    {
        resultOk = get_completion_status(&length, &socketState, &ovl_res);

        if (resultOk) {
            recvBuffer();
        } else {
            // handle error or other cases
        }
        
        sendBuffer();
    }
}
