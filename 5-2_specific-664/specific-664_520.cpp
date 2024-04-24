#include <Windows.h>
#include <iostream>

typedef NTSTATUS(NTAPI* pNtQueryObject)(
    HANDLE ObjectHandle,
    int ObjectInformationClass,
    PVOID ObjectInformation,
    ULONG ObjectInformationLength,
    PULONG ReturnLength
);

int GetProcessIdFromHandle(HANDLE handle) {
    HMODULE hNtdll = GetModuleHandle(L"ntdll.dll");
    if (hNtdll == NULL) {
        return 0;
    }

    pNtQueryObject NtQueryObject = (pNtQueryObject)GetProcAddress(hNtdll, "NtQueryObject");
    if (NtQueryObject == NULL) {
        return 0;
    }

    ULONG pid = 0;
    NTSTATUS status = NtQueryObject(handle, 1, &pid, sizeof(ULONG), NULL);

    if (status != 0) {
        return 0;
    }

    return pid;
}

int main() {
    // Assuming you have a valid handle in 'yourHandle'
    HANDLE yourHandle = /* Your handle here */;

    int pid = GetProcessIdFromHandle(yourHandle);
    if (pid != 0) {
        std::cout << "PID: " << pid << std::endl;
    }
    else {
        std::cout << "Error getting PID from handle" << std::endl;
    }

    return 0;
}
