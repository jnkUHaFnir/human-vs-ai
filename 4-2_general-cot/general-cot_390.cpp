#include <iostream>
#include <winsock2.h>
#pragma comment(lib,"ws2_32.lib")

static DWORD WINAPI ClientWorkerThread(LPVOID lpParameter);

int main(void)
{
    WSADATA WsaDat;
    if (WSAStartup(MAKEWORD(2, 2), &WsaDat) != NO_ERROR) {
        std::cerr << "WSAStartup failed\n";
        return 1;
    }

    // Step 1 - Create an I/O completion port.
    HANDLE hCompletionPort = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 0);
    if (!hCompletionPort) {
        std::cerr << "Error creating completion port\n";
        return 1;
    }

    // Step 2 - Find how many processors.
    SYSTEM_INFO systemInfo;
    GetSystemInfo(&systemInfo);
    const int nNumberOfProcessors = systemInfo.dwNumberOfProcessors;

    // Step 3 - Create worker threads.
    for (int i = 0; i < nNumberOfProcessors; i++)
    {
        HANDLE hThread = CreateThread(NULL, 0, ClientWorkerThread, hCompletionPort, 0, NULL);
        if (!hThread) {
            std::cerr << "Error creating worker thread\n";
            return 1;
        }
        CloseHandle(hThread);
    }

    // Step 4 - Create a socket.
    SOCKET Socket = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, WSA_FLAG_OVERLAPPED);
    if (Socket == INVALID_SOCKET) {
        std::cerr << "Error creating socket\n";
        return 1;
    }

    struct hostent* host;
    if ((host = gethostbyname("localhost")) == NULL) {
        std::cerr << "Error getting host by name\n";
        return 1;
    }

    SOCKADDR_IN SockAddr;
    SockAddr.sin_family = AF_INET;
    SockAddr.sin_addr.s_addr = *((unsigned long*)host->h_addr);
    SockAddr.sin_port = htons(8888);

    // Step 5 - Associate the socket with the I/O completion port.
    CreateIoCompletionPort((HANDLE)Socket, hCompletionPort, (ULONG_PTR)0, 0);

    if (WSAConnect(Socket, (SOCKADDR*)(&SockAddr), sizeof(SockAddr), NULL, NULL, NULL, NULL) == SOCKET_ERROR) {
        std::cerr << "Error connecting to server\n";
        return 1;
    }

    char buffer[1000];
    memset(buffer, 0, sizeof(buffer));
    WSABUF wsaBuf = { static_cast<ULONG>(strlen(buffer)), buffer };
    DWORD dwReceivedBytes = 0;
    DWORD dwFlags = 0;
    WSAOVERLAPPED wsaOverlapped;
    SecureZeroMemory((PVOID)&wsaOverlapped, sizeof(wsaOverlapped));
    wsaOverlapped.hEvent = WSACreateEvent();

    for (;;) {
        WSARecv(Socket, &wsaBuf, 1, &dwReceivedBytes, &dwFlags, &wsaOverlapped, NULL);
        std::cout << wsaBuf.buf;

        Sleep(1000);
    }

    closesocket(Socket);
    WSACleanup();

    system("PAUSE");
    return 0;
}

static DWORD WINAPI ClientWorkerThread(LPVOID lpParameter)
{
    HANDLE hCompletionPort = (HANDLE)lpParameter;
    DWORD dwBytesTransferred = 0;

    while (TRUE) {
        BOOL bRet = GetQueuedCompletionStatus(hCompletionPort, &dwBytesTransferred, static_cast<PULONG_PTR>(0), reinterpret_cast<LPOVERLAPPED*>(0), INFINITE);

        if (!bRet) {
            DWORD dwError = GetLastError();
            std::cerr << "Error in worker thread: " << dwError << std::endl;
        }
    }

    return 0;
}
