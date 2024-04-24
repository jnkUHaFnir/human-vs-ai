#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h> // for gethostbyname
#pragma comment(lib,"ws2_32.lib")

static DWORD WINAPI ClientWorkerThread(LPVOID lpParameter);

int main(void)
{
    WSADATA WsaDat;
    if (WSAStartup(MAKEWORD(2, 2), &WsaDat) != NO_ERROR)
        return 0;

    // Steps 1-3: Create I/O completion port and worker threads
    HANDLE hCompletionPort = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 0);
    if (!hCompletionPort)
        return 0;

    SYSTEM_INFO systemInfo;
    GetSystemInfo(&systemInfo);
    const int nNumberOfProcessors = systemInfo.dwNumberOfProcessors;

    for (int i = 0; i < nNumberOfProcessors; i++)
    {
        HANDLE hThread = CreateThread(NULL, 0, ClientWorkerThread, hCompletionPort, 0, NULL);
        CloseHandle(hThread);
    }

    // Create and set up the socket
    SOCKET Socket = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, WSA_FLAG_OVERLAPPED);
    if (Socket == INVALID_SOCKET)
        return 0;

    struct addrinfo* result = NULL;
    struct addrinfo* ptr = NULL;
    struct addrinfo hints;

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    // Resolve the server address and port
    if (getaddrinfo("localhost", "8888", &hints, &result) != 0)
        return 0;

    // Step 5 - Associate the socket with the I/O completion port.
    CreateIoCompletionPort((HANDLE)Socket, hCompletionPort, (ULONG_PTR)0, 0);

    if (WSAConnect(Socket, result->ai_addr, (int)result->ai_addrlen, NULL, NULL, NULL, NULL) == SOCKET_ERROR)
        return 0;

    char buffer[1024]; // Adjust buffer size as needed
    memset(buffer, 0, sizeof(buffer));
    WSABUF wsaBuf = { sizeof(buffer), buffer };
    DWORD dwReceivedBytes = 0;
    DWORD dwFlags = 0;
    WSAOVERLAPPED wsaOverlapped;
    SecureZeroMemory((PVOID)&wsaOverlapped, sizeof(wsaOverlapped));
    wsaOverlapped.hEvent = WSACreateEvent();

    for (;;)
    {
        // Start the asynchronous receive operation
        WSARecv(Socket, &wsaBuf, 1, &dwReceivedBytes, &dwFlags, &wsaOverlapped, NULL);

        // Process received data in the worker thread
        Sleep(1000);
    }

    WSACleanup();
    return 0;
}

static DWORD WINAPI ClientWorkerThread(LPVOID lpParameter)
{
    HANDLE hCompletionPort = (HANDLE)lpParameter;
    DWORD dwBytesTransferred = 0;
    OVERLAPPED* pOverlapped = NULL;
    DWORD dwCompletionKey = 0;

    while (TRUE)
    {
        BOOL bRet = GetQueuedCompletionStatus(hCompletionPort, &dwBytesTransferred, &dwCompletionKey, &pOverlapped, INFINITE);
        if (bRet)
        {
            // Process the received data accordingly
        }
    }

    return 0;
}
