static const int BUFFER_SIZE = 1000;

int main(void)
{
    // Initialization and setup code

    char sendBuffer[BUFFER_SIZE] = {0};
    char recvBuffer[BUFFER_SIZE] = {0};

    WSABUF wsaSendBuf = {BUFFER_SIZE, sendBuffer};
    WSABUF wsaRecvBuf = {BUFFER_SIZE, recvBuffer};
    
    // Main loop
    for (;;)
    {
        WSARecv(Socket, &wsaRecvBuf, 1, &dwReceivedBytes, &dwFlags, &wsaOverlapped, NULL);
        if (dwReceivedBytes > 0)
        {
            std::cout << "Received: " << recvBuffer << std::endl;
        }

        // Prepare for the next receive operation
        memset(recvBuffer, 0, BUFFER_SIZE);
        
        // Handle sending operations
        // WSASend(Socket, &wsaSendBuf, 1, &dwSendBytes, 0, &wsaOverlapped, NULL);

        // Error handling
        int nError = WSAGetLastError();
        if (nError != WSAEWOULDBLOCK && nError != 0)
        {
            std::cout << "Winsock error code: " << nError << std::endl;
            std::cout << "Server disconnected!" << std::endl;
            shutdown(Socket, SD_SEND);
            closesocket(Socket);
            
            break;
        }
        Sleep(1000);
    }

    // Clean up code
    system("PAUSE");
    return 0;
}
