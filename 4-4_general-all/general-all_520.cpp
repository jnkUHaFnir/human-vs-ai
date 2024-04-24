#include <Windows.h>
#include <iostream>

int main() {
    // Assume hOriginalHandle is the handle that you want to get the process ID from

    // Duplicate the handle with PROCESS_QUERY_INFORMATION access right
    HANDLE hDuplicateHandle;
    if (!DuplicateHandle(GetCurrentProcess(), hOriginalHandle, GetCurrentProcess(), &hDuplicateHandle, PROCESS_QUERY_INFORMATION, FALSE, 0)) {
        DWORD dwError = GetLastError();
        std::cerr << "DuplicateHandle failed with error code: " << dwError << std::endl;
        return 1;
    }

    // Get the process ID from the duplicated handle
    DWORD dwProcessId = 0;
    dwProcessId = GetProcessId(hDuplicateHandle);
    if (dwProcessId == 0) {
        DWORD dwError = GetLastError();
        std::cerr << "GetProcessId failed with error code: " << dwError << std::endl;
    } else {
        std::cout << "Process ID: " << dwProcessId << std::endl;
    }

    // Close the duplicated handle
    CloseHandle(hDuplicateHandle);

    return 0;
}
