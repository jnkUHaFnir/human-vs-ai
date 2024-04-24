#include <windows.h>
#include <iostream>

int main() {
    const char* driveLetter = "E:"; // Drive letter of the USB drive
    HWND hWnd = FindWindow("CabinetWClass", NULL); // Find the Explorer window

    while (hWnd != NULL) {
        char windowTitle[256];
        GetWindowText(hWnd, windowTitle, sizeof(windowTitle)); // Get the window title

        // Check if the window title contains the drive letter
        if (strstr(windowTitle, driveLetter) != NULL) {
            // Send a close message to the window
            SendMessage(hWnd, WM_CLOSE, 0, 0);
            std::cout << "Closed window: " << windowTitle << std::endl;
        }

        // Find the next Explorer window
        hWnd = FindWindowEx(NULL, hWnd, "CabinetWClass", NULL);
    }

    return 0;
}
