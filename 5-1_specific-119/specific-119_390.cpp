static DWORD WINAPI ClientWorkerThread(LPVOID lpParameter)
{
    HANDLE hCompletionPort = (HANDLE)lpParameter;
    DWORD dwBytesTransferred = 0;
    ULONG_PTR completionKey;
    LPOVERLAPPED overlapped;

    while (TRUE)
    {
        BOOL bRet = GetQueuedCompletionStatus(hCompletionPort, &dwBytesTransferred, &completionKey, &overlapped, INFINITE);

        if (!bRet)
        {
            // Handle error
            DWORD err = GetLastError();
            std::cout << "Error in GetQueuedCompletionStatus: " << err << std::endl;
            continue;
        }

        if (dwBytesTransferred == 0)
        {
            // Connection closed
            std::cout << "Server disconnected!" << std::endl;
            break;
        }

        if (overlapped)
        {
            WSABUF* wsaBuf = (WSABUF*)overlapped->hEvent;
            std::cout << "Received: " << wsaBuf->buf << std::endl;
        }
    }

    return 0;
}
