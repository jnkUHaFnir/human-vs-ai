#include <Windows.h>
#include <iostream>

DWORD GetProcessIdFromHandle(HANDLE handle) {
    DWORD pid = 0;

    if (!GetProcessIdOfHandle(handle, &pid)) {
        // Handle error, handle retrieval failure
        std::cerr << "Error getting process ID from handle. Error code: " << GetLastError() << std::endl;
    }

    return pid;
}

int main() {
    // Assuming you have a valid handle in your application
    HANDLE someHandle = /* Your handle here */;

    DWORD processId = GetProcessIdFromHandle(someHandle);
    
    if (processId != 0) {
        std::cout << "Process ID associated with the handle: " << processId << std::endl;
    } else {
        std::cerr << "Failed to retrieve the process ID from the handle." << std::endl;
    }

    // Close the handle when done with it to avoid resource leaks
    CloseHandle(someHandle);

    return 0;
}
