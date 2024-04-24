#include <Windows.h>
#include <iostream>

DWORD GetProcessIdFromHandle(HANDLE hProcess) {
    DWORD dwProcessId = 0;
    HMODULE hModule;
    DWORD cbNeeded;

    if (EnumProcessModules(hProcess, &hModule, sizeof(hModule), &cbNeeded)) {
        dwProcessId = GetProcessIdOfObject(hModule);
    }

    return dwProcessId;
}

int main() {
    HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, <your_handle_pid>);
    if (hProcess == NULL) {
        std::cout << "Failed to open process. Error code: " << GetLastError() << std::endl;
        return 1;
    }

    DWORD processId = GetProcessIdFromHandle(hProcess);

    if (processId != 0) {
        std::cout << "Process ID: " << processId << std::endl;
    } else {
        std::cout << "Failed to get process ID." << std::endl;
    }

    CloseHandle(hProcess);

    return 0;
}
