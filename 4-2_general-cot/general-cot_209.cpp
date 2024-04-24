// Code to create a listening socket and associate it with IO completion port
// Assume necessary functions and variables are defined and initialized

OVERLAPPED overlapped;
memset(&overlapped, 0, sizeof(overlapped);
DWORD bytesReceived = 0;

// Prepare buffer for AcceptEx function
char buffer[sizeof(sockaddr_in) + 16 * 2];
DWORD bufferSize = sizeof(sockaddr_in) + 16 * 2;

// Call AcceptEx function
if (!AcceptEx(AcceptorSock, newSock, buffer, 0, 
              bufferSize, bufferSize, &bytesReceived, &overlapped)) {
    int acceptError = WSAGetLastError();
    if (acceptError != ERROR_IO_PENDING) {
        cerr << "AcceptEx failed with error: " << acceptError << endl;
        // Handle the error as needed and break out of the loop
        break;
    }
}

// Check for completion of AcceptEx in an IOCP completion loop
// This loop should handle completion of multiple AcceptEx operations
// Code for completion loop is not included here for brevity
