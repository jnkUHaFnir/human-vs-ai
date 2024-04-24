// Add acceptor socket file handle to be observed by the completion port
if (CreateIoCompletionPort((HANDLE)AcceptorSock, hCompletionPort, NEW_CONNECTION, 0) != hCompletionPort)
    ErrorAbort("A new completion port has been created instead of using the existing one");
cout << "Acceptor socket associated with the completion port\n";

while (true)
{
    memset(&over, 0, sizeof(over));
    SOCKET newAcceptedSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); // Create a new socket for the accepted connection
    if (AcceptEx(AcceptorSock, newAcceptedSock, lpOutputBuf, outBufLen - ((sizeof(sockaddr_in) + 16) * 2), sizeof(sockaddr_in) + 16, sizeof(sockaddr_in) + 16, &dwBytes, &over) == FALSE)
    {
        int x = WSAGetLastError();
        if (x != WSA_IO_PENDING)
            ErrorAbort("Could not acceptex a new connection");
    }
    
    // Do something with the newAcceptedSock (e.g., associate it with a completion port and handle the connection)
}
