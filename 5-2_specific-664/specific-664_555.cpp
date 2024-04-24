#include <Windows.h>
#include <Shlwapi.h>
#include <string>
#include <iostream>

// Function to close Explorer windows that have folders open on a specific drive
void closeExplorerWindowsOnDrive(const std::wstring& driveLetter) {
    HWND hwnd = FindWindow(L"Progman", NULL);
    if (hwnd) {
        do {
            hwnd = FindWindowEx(NULL, hwnd, L"WorkerW", NULL);
            HWND hwndSHELLDLL_DefView = FindWindowEx(hwnd, NULL, L"SHELLDLL_DefView", NULL);
            if (hwndSHELLDLL_DefView) {
                HWND hwndSysListView32 = FindWindowEx(hwndSHELLDLL_DefView, NULL, L"SysListView32", NULL);
                if (hwndSysListView32) {
                    wchar_t windowText[MAX_PATH];
                    GetWindowText(hwnd, windowText, MAX_PATH);

                    DWORD pid;
                    GetWindowThreadProcessId(hwnd, &pid);

                    HANDLE process = OpenProcess(PROCESS_TERMINATE, FALSE, pid);
                    if (process) {
                        wchar_t drivePath[MAX_PATH];
                        GetVolumePathNamesForVolumeName((driveLetter + L"\\").c_str(), drivePath, MAX_PATH);
                        
                        if (PathIsDirectory(drivePath)) {
                            SendMessage(hwnd, WM_CLOSE, 0, 0);
                            std::wcout << L"Closed Explorer window with handle: " << hwnd << std::endl;
                        }

                        CloseHandle(process);
                    }
                }
            }
        } while (hwnd);
    }
}

int main() {
    std::wstring driveLetter = L"E:"; // Specify the drive letter of the USB drive
    closeExplorerWindowsOnDrive(driveLetter);
    
    return 0;
}
