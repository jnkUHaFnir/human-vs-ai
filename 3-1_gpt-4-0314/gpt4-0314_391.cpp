// Start an async read operation
WSABUF wsaBuf;
wsaBuf.buf = sock_state.buf;
wsaBuf.len = sizeof(sock_state.buf);
DWORD dwReceivedBytes = 0;
DWORD dwFlags = 0;
WSAOVERLAPPED sock_ovl_read;
memset(&sock_ovl_read, 0, sizeof(WSAOVERLAPPED));
WSARecv(sock, &wsaBuf, 1, &dwReceivedBytes, &dwFlags, &sock_ovl_read, NULL);
// main loop
while (true)
{
    // Send a buffer and start an async read
    sendBuffer();
    startAsyncRead();

    // Wait for the send/receive completion events
    while (true)
    {
        DWORD length;
        SocketState* socketState;
        WSAOVERLAPPED* ovl_res;
        BOOL resultOk = get_completion_status(&length, &socketState, &ovl_res);

        if (ovl_res == &sock_ovl)
        {
            // A previous send operation has completed
            break; // break the inner loop - we're ready to send more data
        }
        else if (ovl_res == &sock_ovl_read)
        {
            // A previous receive operation has completed
            // Process the received data and start another async read
            processReceivedData();
            startAsyncRead();
        }
        else
        {
            // handle unexpected completion events
        }
    }
}
