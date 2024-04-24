static DWORD WINAPI ClientWorkerThread(LPVOID lpParameter)
{
    HANDLE hCompletionPort = (HANDLE)lpParameter;
    DWORD dwBytesTransferred = 0;
    DWORD dwCompletionKey;
    LPOVERLAPPED lpOverlapped;

    while (TRUE)
    {
        BOOL bRet = GetQueuedCompletionStatus(hCompletionPort, &dwBytesTransferred, &dwCompletionKey, &lpOverlapped, INFINITE);

        if (!bRet)
        {
            int nError = WSAGetLastError();
            if (nError != ERROR_SUCCESS)
            {
                // Handle error
                continue; // Skip processing
            }
        }

        // Process the received data
        WSABUF* wsaBuf = (WSABUF*)lpOverlapped;
        // Ensure null-terminated string before printing
        char buffer[1001]; // Assuming buffer size is 1000
        memcpy(buffer, wsaBuf->buf, dwBytesTransferred);
        buffer[dwBytesTransferred] = '\0'; // Null-terminate the string

        // Print the received data
        std::cout << buffer;
    }

    return 0;
}
