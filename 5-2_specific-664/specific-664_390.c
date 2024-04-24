static void run(void)
{
    DWORD length;
    BOOL resultOk;
    WSAOVERLAPPED* ovl_res;
    SocketState* socketState;

    for (;;)
    {
        sendBuffer();

        resultOk = get_completion_status(&length, &socketState, &ovl_res);

        // Check if the send operation was successful
        if (resultOk)
        {
            printf("* send operation completed successfully\n");

            // Now you can proceed to receive the response
            recvBuffer();
        }
        else
        {
            // Handle send operation failure
            printf("* error in send operation\n");
            exit(1);
        }
    }
}
