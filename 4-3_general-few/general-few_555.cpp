#include <windows.h>
#include <cstdio>

int main() {
    // Drive letter of the USB drive you want to eject
    char driveLetter = 'E';

    // Concatenate the drive letter with the rest of the path
    char path[MAX_PATH];
    sprintf(path, ":%c\\", driveLetter);

    // Find all top-level windows
    HWND hwnd = GetTopWindow(NULL);
    while (hwnd) {
        char windowPath[MAX_PATH];
        GetWindowModuleFileName(hwnd, windowPath, MAX_PATH);

        // Check if the window belongs to the specified drive
        if (strstr(windowPath, path) != NULL) {
            // Send the WM_CLOSE message to the window
            SendMessage(hwnd, WM_CLOSE, 0, 0);
        }

        // Move to the next top-level window
        hwnd = GetNextWindow(hwnd, GW_HWNDNEXT);
    }

    return 0;
}
