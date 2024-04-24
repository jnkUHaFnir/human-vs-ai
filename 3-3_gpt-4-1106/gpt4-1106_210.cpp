#include <iostream>
#include <winsock2.h>
#include <mswsock.h>

#pragma comment(lib, "ws2_32.lib")

struct OverlappedPlus {
    WSAOVERLAPPED overlapped;
    WSABUF wsabuf;
    char buffer[1000];
    DWORD bytesTransferred;
    DWORD flags;
    SOCKET socket;
};

static DWORD WINAPI ClientWorkerThread(LPVOID lpParameter);

int main(void) {
    WSADATA WsaDat;
    if (WSAStartup(MAKEWORD(2, 2), &WsaDat) != NO_ERROR)
        return 0;

    // Create an I/O completion port.
    HANDLE hCompletionPort = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 0);
    if (!hCompletionPort)
        return 0;

    // Create a socket.
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

    // Associate the socket with the I/O completion port.
    CreateIoCompletionPort((HANDLE)Socket, hCompletionPort, (ULONG_PTR)0, 0);

    if (WSAConnect(Socket, (SOCKADDR*)(&SockAddr), sizeof(SockAddr), NULL, NULL, NULL, NULL) == SOCKET_ERROR)
        return 0;

    // Launch the worker thread.
    HANDLE hThread = CreateThread(NULL, 0, ClientWorkerThread, hCompletionPort, 0, NULL);

    // Update the overlapped structure for receive.
    OverlappedPlus* overlappedPlus = new OverlappedPlus();
    SecureZeroMemory((PVOID)overlappedPlus, sizeof(*overlappedPlus));
    overlappedPlus->wsabuf.buf = overlappedPlus->buffer;
    overlappedPlus->wsabuf.len = sizeof(overlappedPlus->buffer);
    overlappedPlus->socket = Socket;

    // Post an asynchronous receive to the server.
    DWORD dwFlags = 0;
    WSARecv(Socket, &overlappedPlus->wsabuf, 1, NULL, &dwFlags, &overlappedPlus->overlapped, NULL);

    // Wait for the worker thread to complete.
    WaitForSingleObject(hThread, INFINITE);

    // Cleanup.
    closesocket(Socket);
    WSACleanup();
    CloseHandle(hThread);
    delete overlappedPlus;

    system("PAUSE");
    return 0;
}

static DWORD WINAPI ClientWorkerThread(LPVOID lpParameter) {
    HANDLE hCompletionPort = (HANDLE)lpParameter;
    DWORD dwBytesTransferred = 0;
    ULONG_PTR completionKey;
    OverlappedPlus* pov = nullptr;

    while (TRUE) {
        BOOL bRet = GetQueuedCompletionStatus(hCompletionPort, &dwBytesTransferred, &completionKey, (LPOVERLAPPED*)&pov, INFINITE);
        if (!bRet) {
            std::cerr << "GetQueuedCompletionStatus failed with error: " << GetLastError() << std::endl;
            break;
        }
        if (dwBytesTransferred == 0) {
            // Connection has been closed gracefully.
            break;
        }
        // Ensure null-termination.
        pov->buffer[dwBytesTransferred] = '\0';
        std::cout << "Received: " << pov->buffer << std::endl;

        // Post another receive - this keeps the cycle going.
        dwBytesTransferred = 0;
        memset(pov->buffer, 0, sizeof(pov->buffer));
        WSARecv(pov->socket, &pov->wsabuf, 1, &dwBytesTransferred, &pov->flags, &pov->overlapped, NULL);
    }

    // Cleanup on exit
    closesocket(pov->socket);
    delete pov;
    return 0;
}
