    #include <iostream>  
    #include <winsock2.h>  
    #pragma comment(lib,"ws2_32.lib")  
    
    typedef struct
    {
        WSAOVERLAPPED Overlapped;
        SOCKET Socket;
        WSABUF wsaBuf;
        BYTE Buffer[1024];
    } PER_IO_DATA, * LPPER_IO_DATA; 
      
    
    static DWORD WINAPI ServerWorkerThread(LPVOID lpParameter)
    {
        HANDLE hCompletionPort = (HANDLE)lpParameter;
        DWORD NumBytesSent = 0;
        ULONG CompletionKey;
        LPPER_IO_DATA PerIoData;
    
        while (GetQueuedCompletionStatus(hCompletionPort, &NumBytesSent, &CompletionKey, (LPOVERLAPPED*)&PerIoData, INFINITE))    
        {
            if (!PerIoData)
                continue;
    
            if (NumBytesSent == 0)
            {
                std::cout << "Client disconnected!\r\n\r\n";
            }
            else
            {
                PerIoData->wsaBuf.len = strlen(pPerIoData->wsaBuf.buf);
    
                if (WSASend(PerIoData->Socket, &(PerIoData->wsaBuf), 1, NULL, 0, &(PerIoData->Overlapped), NULL) == 0)
                    continue;
    
                if (WSAGetLastError() == WSA_IO_PENDING)
                    continue;
            }
    
            closesocket(PerIoData->Socket);
            delete PerIoData;
        }
    
        return 0;
    } 
    int main()  
    {  
        WSADATA WsaDat;  
        if (WSAStartup(MAKEWORD(2,2), &WsaDat) != 0)
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
            HANDLE hThread = CreateThread(NULL, 0, ServerWorkerThread, hCompletionPort, 0, NULL);
            CloseHandle(hThread);
        } 
    
        // Step 4 - Create a socket. 
        SOCKET listenSocket = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, WSA_FLAG_OVERLAPPED);  
      
        SOCKADDR_IN server;
        ZeroMemory(&server, sizeof(server));
        server.sin_family = AF_INET;  
        server.sin_addr.s_addr = INADDR_ANY;  
        server.sin_port = htons(8888);  
      
        if (bind(listenSocket, (SOCKADDR*)(&server), sizeof(server)) != 0)
            return 0;  
      
        if (listen(listenSocket, 1) != 0)
            return 0;  
      
        std::cout << "Waiting for incoming connection...\r\n";  
    
        SOCKET acceptSocket = SOCKET_ERROR;  
        while (acceptSocket == SOCKET_ERROR)  
        {  
            sockaddr_in saClient;  
            int nClientSize = sizeof(saClient);  
            acceptSocket = WSAAccept(listenSocket, (SOCKADDR*)&saClient, &nClientSize, NULL, NULL);  
        }  
      
        std::cout << "Client connected!\r\n\r\n";  
      
        // Step 5 - Associate the socket with the I/O completion port.
        CreateIoCompletionPort((HANDLE)acceptSocket, hCompletionPort, 0, 0); 
    
        LPPER_IO_DATA pPerIoData = new PER_IO_DATA;
        ZeroMemory(pPerIoData, sizeof(PER_IO_DATA));
    
        strcpy((char*)pPerIoData->Buffer, "Welcome to the server!\r\n");  
    
        pPerIoData->Overlapped.hEvent = WSACreateEvent(); 
        pPerIoData->wsaBuf.buf = (char*) pPerIoData->Buffer;  
        pPerIoData->wsaBuf.len = strlen(pPerIoData->wsaBuf.buf);  
          
        if (WSASend(acceptSocket, &(pPerIoData->wsaBuf), 1, NULL, 0, &(pPerIoData->Overlapped), NULL) == SOCKET_ERROR)
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
      
        shutdown(acceptSocket, SD_BOTH);  
        closesocket(acceptSocket);  
    
        WSACleanup();  
        return 0;  
    }
    