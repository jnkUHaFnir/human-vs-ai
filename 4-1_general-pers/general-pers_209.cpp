#include <iostream>
#include <Winsock2.h>
#include <WS2tcpip.h>
#include <MSWSock.h>

#pragma comment(lib, "Ws2_32.lib")

#define NEW_CONNECTION 0

void StartWinsock() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "WSAStartup failed\n";
        exit(1);
    }
}

void ErrorAbort(const char* errorMsg) {
    std::cerr << "Error: " << errorMsg << std::endl;
    exit(1);
}

int main() {
    StartWinsock();

    SOCKET AcceptorSock = INVALID_SOCKET;
    SOCKET NewConnectionSock = INVALID_SOCKET;

    // Create Acceptor Socket
    AcceptorSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (AcceptorSock == INVALID_SOCKET) {
        ErrorAbort("Failed to create Acceptor Socket");
    }

    // Bind Acceptor Socket to the listening port
    SOCKADDR_IN serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddr.sin_port = htons(12345);

    if (bind(AcceptorSock, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        ErrorAbort("Failed to bind Acceptor Socket");
    }

    // Start Listening on Acceptor Socket
    if (listen(AcceptorSock, SOMAXCONN) == SOCKET_ERROR) {
        ErrorAbort("Failed to listen on Acceptor Socket");
    }

    // Initialize some buffer and structures
    char lpOutputBuf[1024];
    DWORD dwBytes = 0;
    OVERLAPPED overlapped;
    ZeroMemory(&overlapped, sizeof(overlapped));

    GUID guidAcceptEx = WSAID_ACCEPTEX;
    LPFN_ACCEPTEX lpfnAcceptEx = NULL;
    DWORD bytes;

    // Load AcceptEx function
    if (WSAIoctl(AcceptorSock, SIO_GET_EXTENSION_FUNCTION_POINTER, &guidAcceptEx, sizeof(guidAcceptEx), &lpfnAcceptEx, sizeof(lpfnAcceptEx), &bytes, NULL, NULL) == SOCKET_ERROR) {
        ErrorAbort("Failed to load AcceptEx function");
    }

    // AcceptEx
    if (!lpfnAcceptEx(AcceptorSock, NewConnectionSock, lpOutputBuf, 0, sizeof(SOCKADDR_IN) + 16, sizeof(SOCKADDR_IN) + 16, &dwBytes, &overlapped)) {
        if (WSAGetLastError() != ERROR_IO_PENDING) {
            ErrorAbort("Failed to accept new connection");
        }
    }

    // Clean up
    closesocket(AcceptorSock);
    closesocket(NewConnectionSock);
    WSACleanup();

    return 0;
}
