#include <iostream>
#include <winsock2.h>
#pragma comment(lib,"ws2_32.lib")

static DWORD WINAPI ClientWorkerThread(LPVOID lpParameter);

int main(void)
{
    WSADATA WsaDat;
    if (WSAStartup(MAKEWORD(2, 2), &WsaDat) != 0)
        return 0;

    HANDLE hCompletionPort = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 0);
    if (!hCompletionPort)
        return 0;

    SYSTEM_INFO systemInfo;
    GetSystemInfo(&systemInfo);
    const int nNumberOfProcessors = systemInfo.dwNumberOfProcessors;

    for (int i = 0; i < nNumberOfProcessors; i++)
    {
        HANDLE hThread = CreateThread(NULL, 0, ClientWorkerThread, hCompletionPort, 0, NULL);
        if (!hThread)
            return 0;
        // CloseHandle(hThread); // Do not close the handle, let the worker thread handle it
    }

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

    CreateIoCompletionPort((HANDLE)Socket, hCompletionPort, 0, 0);

    if (WSAConnect(Socket, (SOCKADDR*)(&SockAddr), sizeof(SockAddr), NULL, NULL, NULL, NULL) == SOCKET_ERROR)
        return 0;

    char buffer[1000];
    memset(buffer, 0, sizeof(buffer));
    WSABUF wsaBuf = { sizeof(buffer), buffer };
    DWORD dwReceivedBytes = 0, dwFlags = 0;
    WSAOVERLAPPED wsaOverlapped;
    SecureZeroMemory(&wsaOverlapped, sizeof(wsaOverlapped));
    wsaOverlapped.hEvent = WSACreateEvent();

    for (;;)
    {
        WSARecv(Socket, &wsaBuf, 1, &dwReceivedBytes, &dwFlags, &wsaOverlapped, NULL);
        // Handle received data appropriately

        int nError = WSAGetLastError();
        if (nError != WSAEWOULDBLOCK && nError != 0)
        {
            std::cout << "Winsock error code: " << nError << "\n";
            break;
        }

        Sleep(1000);
    }

    WSACleanup();
    return 0;
}

static DWORD WINAPI ClientWorkerThread(LPVOID lpParameter)
{
    HANDLE hCompletionPort = (HANDLE)lpParameter;
    DWORD dwBytesTransferred = 0;
    ULONG_PTR completionKey = 0;
    LPOVERLAPPED overlapped = NULL;

    while (TRUE)
    {
        BOOL bRet = GetQueuedCompletionStatus(hCompletionPort, &dwBytesTransferred, &completionKey, &overlapped, INFINITE);
        // Process the overlapped operation completion
    }

    return 0;
}
