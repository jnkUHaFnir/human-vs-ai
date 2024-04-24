#include <iostream>
#include <winsock2.h>
#pragma comment(lib,"ws2_32.lib")

// Worker thread function to handle IOCP completion events
static DWORD WINAPI ClientWorkerThread(LPVOID lpParameter);

int main(void)
{
    WSADATA WsaDat;
    if (WSAStartup(MAKEWORD(2, 2), &WsaDat) != NO_ERROR)
        return 0;

    // Step 1 - Create an I/O completion port.
    HANDLE hCompletionPort = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 0);
    if (!hCompletionPort)
        return 0;

    // Step 2 - Create worker threads.
    SYSTEM_INFO systemInfo;
    GetSystemInfo(&systemInfo);
    const int nNumberOfProcessors = systemInfo.dwNumberOfProcessors;
    
    for (int i = 0; i < nNumberOfProcessors; i++)
    {
        HANDLE hThread = CreateThread(NULL, 0, ClientWorkerThread, hCompletionPort, 0, NULL);
        CloseHandle(hThread);
    }

    // Step 3 - Create a socket.
    SOCKET Socket = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, WSA_FLAG_OVERLAPPED);
    if (Socket == INVALID_SOCKET)
        return 0;

    struct hostent* host;
    if ((host = gethostbyname("localhost")) == NULL)
        return 0;

    SOCKADDR_IN SockAddr;
    SockAddr.sin_family = AF_INET;
    SockAddr.sin_addr.s_addr = *((unsigned long*)host->h_addr);
    SockAddr.sin_port = htons(8888);

    // Step 4 - Associate the socket with the I/O completion port.
    CreateIoCompletionPort((HANDLE)Socket, hCompletionPort, (ULONG_PTR)0, 0);
    
    if (WSAConnect(Socket, (SOCKADDR*)(&SockAddr), sizeof(SockAddr), NULL, NULL, NULL, NULL) == SOCKET_ERROR)
        return 0;

    char buffer[1000];
    memset(buffer, 0, 999);
    WSABUF wsaBuf = { strlen(buffer), buffer };
    DWORD dwReceivedBytes = 0;
    DWORD dwFlags = 0;
    WSAOVERLAPPED wsaOverlapped;
    SecureZeroMemory((PVOID)&wsaOverlapped, sizeof(wsaOverlapped));

    // Use WSARecv instead of recv
    WSARecv(Socket, &wsaBuf, 1, &dwReceivedBytes, &dwFlags, &wsaOverlapped, NULL);

    WSACleanup();
    system("PAUSE");
    return 0;
}

// Worker thread to handle completion events
static DWORD WINAPI ClientWorkerThread(LPVOID lpParameter)
{
    HANDLE hCompletionPort = (HANDLE)lpParameter;
    DWORD dwBytesTransferred = 0;
    LPOVERLAPPED lpOverlapped;
    
    while (TRUE)
    {
        BOOL bRet = GetQueuedCompletionStatus(hCompletionPort, &dwBytesTransferred, NULL, &lpOverlapped, INFINITE);
        // Handle completion event for lpOverlapped
    }

    return 0;
}
