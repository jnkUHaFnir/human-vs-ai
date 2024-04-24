#include <stdio.h>
#include <winsock2.h>
#include <windows.h>
#pragma comment(lib,"ws2_32.lib")

enum {
    BUFLEN = 1000,
    SERVICE_PORT = 4000,
    SERVER_ADDRESS = INADDR_LOOPBACK
};

typedef struct _SocketState {
    SOCKET socket;
    char buf[1024];
    WSABUF wsabuf;
    WSAOVERLAPPED overlapped;
    DWORD bytesReceived;
} SocketState;

static SOCKET clientSocket;

void InitWinsock() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        fprintf(stderr, "WSAStartup failed.\n");
        exit(1);
    }
}

void CreateSocketAndConnect() {
    clientSocket = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, WSA_FLAG_OVERLAPPED);
    if (clientSocket == INVALID_SOCKET) {
        fprintf(stderr, "Error creating socket. Error code: %d\n", WSAGetLastError());
        exit(1);
    }

    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serverAddr.sin_port = htons(SERVICE_PORT);

    if (WSAConnect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr), NULL, NULL, NULL, NULL) == SOCKET_ERROR) {
        fprintf(stderr, "Error connecting to server. Error code: %d\n", WSAGetLastError());
        exit(1);
    }
}

void Cleanup() {
    closesocket(clientSocket);
    WSACleanup();
}

int main() {
    InitWinsock();
    CreateSocketAndConnect();

    SocketState clientState;
    memset(&clientState, 0, sizeof(SocketState));
    clientState.socket = clientSocket;

    while (1) {
        // Receive data
        if (WSARecv(clientState.socket, &clientState.wsabuf, 1, &clientState.bytesReceived, 0, &clientState.overlapped, NULL) == SOCKET_ERROR) {
            int err = WSAGetLastError();
            if (err != WSA_IO_PENDING) {
                fprintf(stderr, "Error in WSARecv. Error code: %d\n", err);
                break;
            }
        }

        // Handle received data if any
        if (clientState.bytesReceived > 0) {
            printf("Received data: %s\n", clientState.wsabuf.buf);
            // Process the received data as needed

            // Reset state for next receive
            memset(&clientState, 0, sizeof(SocketState));
        }
    }

    Cleanup();
    return 0;
}
