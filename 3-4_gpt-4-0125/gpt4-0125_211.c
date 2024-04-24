ZeroMemory(&overlapped, sizeof(overlapped)); // Important to zero out the structure
WSABUF wsabuf;
wsabuf.buf = recvBuffer; // recvBuffer should be a pre-allocated buffer for the data
wsabuf.len = sizeof(recvBuffer);
DWORD flags = 0; // Typically starts as 0, may be modified by WSARecv

int result = WSARecv(sock, &wsabuf, 1, NULL, &flags, &overlapped, NULL);

if (result == SOCKET_ERROR && WSAGetLastError() != WSA_IO_PENDING) {
    // An actual error occurred
    printf("WSARecv failed with error: %d\n", WSAGetLastError());
}
