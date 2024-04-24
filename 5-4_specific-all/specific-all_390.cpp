static DWORD WINAPI ClientWorkerThread(LPVOID lpParameter)
{
    HANDLE hCompletionPort = (HANDLE)lpParameter;
    DWORD dwBytesTransferred = 0;
    ULONG_PTR completionKey;
    LPOVERLAPPED overlapped;

    while (TRUE)
    {
        BOOL bRet = GetQueuedCompletionStatus(hCompletionPort, &dwBytesTransferred, &completionKey, &overlapped, INFINITE);

        if (!bRet) {
            DWORD dwError = GetLastError();
            // Handle error
            continue;
        }

        if (completionKey == 0) {
            // Process your completed overlapped I/O operation here
            // For example, check the overlapped structure for operation status
            // Your actual data processing logic should be here
        }
    }

    return 0;
}
