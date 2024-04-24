#include <Windows.h>
#include <string>
#include <vector>
#include <tlhelp32.h>

bool CloseExplorerFoldersOnDrive(const std::wstring& driveLetter) {
    // Get the process ID of each running process
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    PROCESSENTRY32 pe;
    pe.dwSize = sizeof(PROCESSENTRY32);

    if (Process32First(hSnapshot, &pe)) {
        do {
            // Check for Windows Explorer processes
            if (_wcsicmp(pe.szExeFile, L"explorer.exe") == 0) {
                HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe.th32ProcessID);
                if (hProcess) {
                    // Close folders opened on the target drive
                    // Replace "<DriveLetter>:\" with the actual drive letter you're targeting
                    if (PathIsDirectoryOpened(hProcess, wstring(driveLetter + L":\\"))) {
                        // Assuming MyCloseFunction is a hypothetical function to close folders in Explorer
                        MyCloseFunction(hProcess, driveLetter);
                    }
                    CloseHandle(hProcess);
                }
            }
        } while (Process32Next(hSnapshot, &pe));
    }

    CloseHandle(hSnapshot);
    return true; // Successfully closed folders on the drive
}

int main() {
    // Example usage
    CloseExplorerFoldersOnDrive(L"E");
    
    return 0;
}
