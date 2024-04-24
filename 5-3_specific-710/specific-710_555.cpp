#include <Windows.h>
#include <Shobjidl.h>
#include <iostream>
#include <vector>

// Function to check if a window is displaying a folder from a specific drive
bool IsWindowDisplayingDriveFolder(HWND hwnd, const std::wstring& driveLetter)
{
    wchar_t windowPath[MAX_PATH];
    GetWindowModuleFileName(hwnd, windowPath, MAX_PATH);

    // Check if the window path is from the specific drive
    return std::wstring(windowPath).find(driveLetter) != std::string::npos;
}

// Function to close windows displaying folders from a specific drive
void CloseExplorerWindowsForDrive(const std::wstring& driveLetter)
{
    std::vector<HWND> explorerWindows;

    // Enumerate all windows to find Explorer windows
    EnumWindows([](HWND hwnd, LPARAM lParam) -> BOOL {
        DWORD processId;
        GetWindowThreadProcessId(hwnd, &processId);

        // Check if the window belongs to Windows Explorer process
        if (GetProcessId(GetCurrentProcess()) == processId) {
            ((std::vector<HWND>*)lParam)->push_back(hwnd);
        }

        return TRUE;
    }, (LPARAM)&explorerWindows);

    // Close windows displaying folders from the specific drive
    for (HWND hwnd : explorerWindows) {
        if (IsWindowDisplayingDriveFolder(hwnd, driveLetter)) {
            PostMessage(hwnd, WM_CLOSE, 0, 0);
        }
    }
}

int main() {
    // Specify the drive letter of the USB drive you want to eject
    std::wstring driveLetter = L"D:\\";

    // Close Explorer windows displaying folders from the specified drive
    CloseExplorerWindowsForDrive(driveLetter);

    return 0;
}
