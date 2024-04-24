// Prepare the buffers
char lpOutputBuf[1024];
int outBufLen = sizeof(lpOutputBuf) + ((sizeof(sockaddr_in) + 16) * 2); // Calculate the correct buffer size

DWORD dwBytes;
OVERLAPPED over;
SOCKET newSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

while(true)
{
    memset(&over, 0, sizeof(over));
    if(AcceptEx(AcceptorSock, newSock, lpOutputBuf, 0, outBufLen, outBufLen, &dwBytes, &over) == FALSE)
    {
        int x = WSAGetLastError();
        if(x != WSA_IO_PENDING)
            ErrorAbort("Could not acceptex a new connection");
    }
}
