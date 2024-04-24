#include <Windows.h>
#include <winternl.h>

typedef NTSTATUS(NTAPI* pfnNtQueryInformationProcess)(
    HANDLE ProcessHandle,
    PROCESSINFOCLASS ProcessInformationClass,
    PVOID ProcessInformation,
    ULONG ProcessInformationLength,
    PULONG ReturnLength
);

DWORD GetProcessIdFromHandle(HANDLE hProcess) {
    pfnNtQueryInformationProcess NtQueryInformationProcess = 
        (pfnNtQueryInformationProcess)GetProcAddress(GetModuleHandle(TEXT("ntdll.dll")), "NtQueryInformationProcess");

    if (!NtQueryInformationProcess) {
        // Error handling
        return 0;
    }

    PROCESS_BASIC_INFORMATION pbi;
    NTSTATUS status = NtQueryInformationProcess(hProcess, ProcessBasicInformation, &pbi, sizeof(PROCESS_BASIC_INFORMATION), NULL);

    if (!NT_SUCCESS(status)) {
        // Error handling
        return 0;
    }

    return (DWORD)pbi.UniqueProcessId;
}

int main() {
    HANDLE hProcess = /* Your process handle */;
    DWORD pid = GetProcessIdFromHandle(hProcess);
    if (pid != 0) {
        printf("Process ID: %lu\n", pid);
    } else {
        printf("Failed to get process ID\n");
    }

    return 0;
}
