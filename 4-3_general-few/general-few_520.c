#include <Windows.h>

DWORD GetProcessIdOfProcess(HANDLE hProcess) {
    typedef DWORD(WINAPI* _GetProcessIdOfProcess)(HANDLE);
    _GetProcessIdOfProcess pfnGetProcessIdOfProcess = (_GetProcessIdOfProcess)GetProcAddress(GetModuleHandle("kernel32.dll"), "GetProcessId");

    if (pfnGetProcessIdOfProcess) {
        return pfnGetProcessIdOfProcess(hProcess);
    }

    return 0;
}

int main() {
    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processId);

    DWORD processId = GetProcessIdOfProcess(hProcess);

    if (processId != 0) {
        printf("Process ID: %d\n", processId);
    } else {
        printf("Failed to get Process ID\n");
    }

    CloseHandle(hProcess);
    return 0;
}
