static DWORD WINAPI ClientWorkerThread(LPVOID lpParameter) {
    HANDLE hCompletionPort = (HANDLE)lpParameter;
    DWORD dwBytesTransferred;
    ULONG_PTR CompletionKey;
    LPOVERLAPPED lpOverlapped;

    while (TRUE) {
        BOOL bRet = GetQueuedCompletionStatus(hCompletionPort, &dwBytesTransferred, &CompletionKey, &lpOverlapped, INFINITE);
        if (!bRet) {
            // Handle error, possibly by breaking the loop
            continue;
        }

        // Interpret the completion. For example, if you stored a pointer to your data structure in CompletionKey:
        if (dwBytesTransferred == 0) {
            // Possible socket closure.
            continue;
        }

        // Continue based on operation (read or write completed)
    }

    return 0;
}
