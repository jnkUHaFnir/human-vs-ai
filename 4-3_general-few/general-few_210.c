static void run(void)
{
    DWORD length;
    BOOL resultOk;
    WSAOVERLAPPED* ovl_res;
    SocketState* socketState;

    while (1)
    {
        sendBuffer();

        resultOk = get_completion_status(&length, &socketState, &ovl_res);
        if (resultOk) {
            // Process the completion of the send operation here
            // You can check the socketState to determine the operation completed
            // For example, if(socketState->operation == OP_WRITE), proceed to recvBuffer
            recvBuffer();
        } else {
            // Handle the error
            // You can retry the send operation or take appropriate action
        }
    }
}
