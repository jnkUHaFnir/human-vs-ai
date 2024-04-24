#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib,"ws2_32.lib")

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

    // Step 2 - Find how many processors.
    SYSTEM_INFO systemInfo;
    GetSystemInfo(&systemInfo);
    const int nNumberOfProcessors = systemInfo.dwNumberOfProcessors;

    // Step 3 - Create worker threads.
    for (int i = 0; i < nNumberOfProcessors; i++)
    {
        HANDLE hThread = CreateThread(NULL, 0, ClientWorkerThread, hCompletionPort, 0, NULL);
        CloseHandle(hThread);
    }

    // Step 4 - Create a socket.
    SOCKET Socket = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, WSA_FLAG_OVERLAPPED);
    if (Socket == INVALID_SOCKET)
        return 0;

    struct addrinfo* result = NULL;
    struct addrinfo hints;

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    if (getaddrinfo("localhost", "8888", &hints, &result) != 0)
        return 0;

    // Step 5 - Associate the socket with the I/O completion port.
    CreateIoCompletionPort((HANDLE)Socket, hCompletionPort, (ULONG_PTR)0, 0);

    if (WSAConnect(Socket, result->ai_addr, (int)result->ai_addrlen, NULL, NULL, NULL, NULL) == SOCKET_ERROR)
        return 0;

    char buffer[1000];
    memset(buffer, 0, 999);
    WSABUF wsaBuf = {strlen(buffer), buffer};
    DWORD dwReceivedBytes = 0;
    DWORD dwFlags = 0;
    WSAOVERLAPPED wsaOverlapped;
    SecureZeroMemory((PVOID)&wsaOverlapped, sizeof(wsaOverlapped));
    wsaOverlapped.hEvent = WSACreateEvent();

    while (true)
    {
        // Start receiving data
        if (WSARecv(Socket, &wsaBuf, 1, &dwReceivedBytes, &dwFlags, &wsaOverlapped, NULL) == SOCKET_ERROR)
        {
            int nError = WSAGetLastError();
            if (nError != WSA_IO_PENDING)
            {
                std::cout << "WSARecv failed with error: " << nError << std::endl;
                break;
            }
        }

        // Wait for the completion of the receive operation
        if (WSAWaitForMultipleEvents(1, &wsaOverlapped.hEvent, TRUE, WSA_INFINITE, FALSE) == WSA_WAIT_FAILED)
        {
            std::cout << "WSAWaitForMultipleEvents failed" << std::endl;
            break;
        }

        // Process received data from wsaBuf.buf

        // Clear the event for reuse
        WSAResetEvent(wsaOverlapped.hEvent);

        // Send some data
        // WSASend(...)
    }

    freeaddrinfo(result);
    closesocket(Socket);
    WSACleanup();
    system("PAUSE");
    return 0;
}

static DWORD WINAPI ClientWorkerThread(LPVOID lpParameter)
{
    HANDLE hCompletionPort = (HANDLE)lpParameter;
    DWORD dwBytesTransferred = 0;
    ULONG_PTR completionKey;
    LPOVERLAPPED overlapped;

    while (TRUE)
    {
        BOOL bRet = GetQueuedCompletionStatus(hCompletionPort, &dwBytesTransferred, &completionKey, &overlapped, INFINITE);

        if (!bRet)
        {
            DWORD dwErr = GetLastError();
            if (dwErr == ERROR_ABANDONED_WAIT_0)
            {
                std::cout << "GetQueuedCompletionStatus: The I/O completion port has been closed." << std::endl;
                break;
            }
            else
            {
                std::cout << "GetQueuedCompletionStatus failed with error: " << dwErr << std::endl;
            }
        }

        // Process the completed operation based on completionKey and overlapped structure
    }

    return 0;
}
