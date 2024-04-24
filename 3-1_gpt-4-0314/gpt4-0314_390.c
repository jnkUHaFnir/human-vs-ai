if (WSAConnect(Socket, (SOCKADDR*)(&SockAddr), sizeof(SockAddr), NULL, NULL, NULL, NULL) == SOCKET_ERROR)
    return 0;

char buffer[1000];
memset(buffer, 0, 999);
WSABUF wsaBuf = {strlen(buffer), buffer};
DWORD dwSendBytes = 0;
DWORD dwReceivedBytes = 0;
DWORD dwFlags = 0;
WSAOVERLAPPED wsaOverlapped;
SecureZeroMemory((PVOID)&wsaOverlapped, sizeof(wsaOverlapped));
wsaOverlapped.hEvent = WSACreateEvent();

WSARecv(Socket, &wsaBuf, 1, &dwReceivedBytes, &dwFlags, &wsaOverlapped, NULL);
void CALLBACK RecvCompletionRoutine(DWORD dwError,
    DWORD cbTransferred, LPWSAOVERLAPPED lpOverlapped,
    DWORD dwFlags)
{
    std::cout << "Received " << cbTransferred << " bytes\n";
    // You can process the received data here

    // Call WSARecv again to start receiving more data
    WSAOVERLAPPED wsaOverlapped = *lpOverlapped;
    SecureZeroMemory((PVOID)&wsaOverlapped, sizeof(wsaOverlapped));
    wsaOverlapped.hEvent = WSACreateEvent();
    WSABUF wsaBuf = {1000, (char*)wsaOverlapped.Pointer};
    DWORD dwReceivedBytes = 0;
    DWORD dwFlags = 0;
    WSARecv(Socket, &wsaBuf, 1, &dwReceivedBytes, &dwFlags, &wsaOverlapped, RecvCompletionRoutine);
}

void CALLBACK SendCompletionRoutine(DWORD dwError,
    DWORD cbTransferred, LPWSAOVERLAPPED lpOverlapped,
    DWORD dwFlags)
{
    std::cout << "Sent " << cbTransferred << " bytes\n";
}
WSARecv(Socket, &wsaBuf, 1, &dwReceivedBytes, &dwFlags, &wsaOverlapped, RecvCompletionRoutine);
WSASend(Socket, &wsaBuf, 1, &dwSendBytes, 0, &wsaOverlapped, SendCompletionRoutine);
SleepEx(INFINITE, TRUE);
