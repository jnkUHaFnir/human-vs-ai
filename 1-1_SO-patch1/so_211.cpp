    #include <iostream> 
    #include <winsock2.h> 
    #pragma comment(lib, "ws2_32.lib") 
     
    typedef struct 
    { 
        WSAOVERLAPPED Overlapped; 
        SOCKET Socket; 
        WSABUF wsaBuf; 
        char Buffer[1024];
    } PER_IO_DATA, * LPPER_IO_DATA; 
     
    static DWORD WINAPI ClientWorkerThread(LPVOID lpParameter) 
    { 
        HANDLE hCompletionPort = (HANDLE)lpParameter; 
        DWORD NumBytesRecv = 0; 
        ULONG CompletionKey; 
        LPPER_IO_DATA PerIoData; 
     
        while (GetQueuedCompletionStatus(hCompletionPort, &NumBytesRecv, &CompletionKey, (LPOVERLAPPED*)&PerIoData, INFINITE))
        {
            if (!PerIoData)
                continue;
    
            if (NumBytesRecv == 0) 
            {
                std::cout << "Server disconnected!\r\n\r\n";  
            }
            else
            {
                // use PerIoData->Buffer as needed...
                std::cout << std::string(PerIoData->Buffer, NumBytesRecv);
    
                PerIoData->wsaBuf.len = sizeof(PerIoData->Buffer); 
    
                if (WSARecv(PerIoData->Socket, &(PerIoData->wsaBuf), 1, NULL, NULL, &(PerIoData->Overlapped), NULL) == 0)
                    continue;
    
                if (WSAGetLastError() == WSA_IO_PENDING)
                    continue;
            }
    
            closesocket(PerIoData->Socket);
            delete PerIoData;
        } 
     
        return 0; 
    } 
    int main(void) 
    { 
        WSADATA WsaDat; 
        if (WSAStartup(MAKEWORD(2, 2), &WsaDat) != 0)
            return 0; 
     
        // Step 1 - Create an I/O completion port. 
        HANDLE hCompletionPort = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 0); 
        if (!hCompletionPort)
            return 0;
     
        // Step 2 - Find how many processors. 
        SYSTEM_INFO systemInfo; 
        GetSystemInfo(&systemInfo); 
     
        // Step 3 - Create worker threads. 
        for (DWORD i = 0; i < systemInfo.dwNumberOfProcessors; ++i) 
        { 
            HANDLE hThread = CreateThread(NULL, 0, ClientWorkerThread, hCompletionPort, 0, NULL); 
            CloseHandle(hThread); 
        } 
     
        // Step 4 - Create a socket. 
        SOCKET Socket = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, WSA_FLAG_OVERLAPPED); 
        if (Socket == INVALID_SOCKET)
            return 0;
     
        SOCKADDR_IN SockAddr; 
        SockAddr.sin_family = AF_INET; 
        SockAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
        SockAddr.sin_port = htons(8888); 
     
        // Step 5 - Associate the socket with the I/O completion port. 
        CreateIoCompletionPort((HANDLE)Socket, hCompletionPort, 0, 0); 
     
        if (WSAConnect(Socket, (SOCKADDR*)(&SockAddr), sizeof(SockAddr), NULL, NULL, NULL, NULL) == SOCKET_ERROR)
            return 0;
    
        PER_IO_DATA *pPerIoData = new PER_IO_DATA;
        ZeroMemory(pPerIoData, sizeof(PER_IO_DATA)); 
     
        pPerIoData->Socket = Socket; 
        pPerIoData->Overlapped.hEvent = WSACreateEvent(); 
        pPerIoData->wsaBuf.buf = pPerIoData->Buffer; 
        pPerIoData->wsaBuf.len = sizeof(pPerIoData->Buffer); 
    
        if (WSARecv(Socket, &(pPerIoData->wsaBuf), 1, NULL, NULL, &(pPerIoData->Overlapped), NULL) == SOCKET_ERROR)
        {
            if (WSAGetLastError() != WSA_IO_PENDING)
            {
                delete pPerIoData;
                return 0;
            }
        } 
     
        while (TRUE) 
        { 
            Sleep(1000); 
        } 
     
        shutdown(Socket, SD_BOTH); 
        closesocket(Socket); 
    
        WSACleanup(); 
        return 0; 
    } 
     