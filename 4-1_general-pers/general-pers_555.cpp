#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>

void CloseExplorerWindowsForDrive(const std::wstring& driveLetter) {
    std::vector<HWND> explorerWindows;

    // Find all the windows of class "CabinetWClass" which correspond to Explorer windows
    HWND hwnd = FindWindow(L"CabinetWClass", NULL);
    while (hwnd != NULL) {
        wchar_t windowDrive[MAX_PATH];
        if (GetWindowModuleFileName(hwnd, windowDrive, MAX_PATH)) {
            if (std::wstring(windowDrive).find(driveLetter) != std::wstring::npos) {
                explorerWindows.push_back(hwnd);
            }
        }
        hwnd = FindWindowEx(NULL, hwnd, L"CabinetWClass", NULL);
    }

    // Close the identified Explorer windows
    for (const auto& window : explorerWindows) {
        PostMessage(window, WM_CLOSE, 0, 0); // Sends a close message to the window
    }
}

int main() {
    std::wstring driveLetter = L"Z:"; // Change this to the actual drive letter you want to eject

    // Close Explorer windows for the specified drive
    CloseExplorerWindowsForDrive(driveLetter);

    return 0;
}
