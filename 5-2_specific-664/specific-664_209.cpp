#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <MSWSock.h>

#pragma comment(lib, "ws2_32.lib")

void StartWinsock() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "WSAStartup failed" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void ErrorAbort(const char* message) {
    std::cerr << message << std::endl;
    exit(EXIT_FAILURE);
}

int main() {
    StartWinsock();

    SOCKET AcceptorSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (AcceptorSock == INVALID_SOCKET) {
        ErrorAbort("Socket creation failed");
    }

    // Bind and listen code here...

    DWORD dwBytes;
    GUID guidAcceptEx = WSAID_ACCEPTEX;
    LPFN_ACCEPTEX lpfnAcceptEx = nullptr;
    DWORD bytes;

    if (WSAIoctl(AcceptorSock, SIO_GET_EXTENSION_FUNCTION_POINTER, &guidAcceptEx, sizeof(guidAcceptEx), &lpfnAcceptEx, sizeof(lpfnAcceptEx), &bytes, NULL, NULL) == SOCKET_ERROR) {
        closesocket(AcceptorSock);
        ErrorAbort("WSAIoctl failed");
    }

    char lpOutputBuf[1024];
    int outBufLen = 1024 + sizeof(sockaddr_in) + 16;
    OVERLAPPED over;
    SOCKET newSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    while (true) {
        memset(&over, 0, sizeof(over));
        if (!lpfnAcceptEx(AcceptorSock, newSock, lpOutputBuf, 0, sizeof(sockaddr_in) + 16, sizeof(sockaddr_in) + 16, &dwBytes, &over)) {
            int x = WSAGetLastError();
            if (x != ERROR_IO_PENDING) {
                ErrorAbort("Could not acceptex a new connection");
            }
        }
    }

    closesocket(AcceptorSock);
    WSACleanup();
    return 0;
}
