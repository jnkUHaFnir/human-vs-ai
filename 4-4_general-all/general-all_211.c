static void run(void)
{
    DWORD length_send, length_recv;
    BOOL resultOk_send, resultOk_recv;
    WSAOVERLAPPED* ovl_res;
    SocketState* socketState;

    for (;;)
    {
        sendBuffer();

        // Wait for the send operation to complete
        resultOk_send = get_completion_status(&length_send, &socketState, &ovl_res);
        
        // Check if send completed successfully
        if (resultOk_send)
        {
            printf("* send completed successfully\n");

            // Receive the response
            recvBuffer();

            // Wait for the receive operation to complete
            resultOk_recv = get_completion_status(&length_recv, &socketState, &ovl_res);

            // Check if receive completed successfully
            if (resultOk_recv)
            {
                printf("* receive completed successfully\n");
            }
            else
            {
                printf("* receive completion error\n");
                exit(1);
            }
        }
        else
        {
            printf("* send completion error\n");
            exit(1);
        }
    }
}
