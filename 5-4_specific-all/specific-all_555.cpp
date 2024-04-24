#include <windows.h>
#include <vector>
#include <iostream>

int main() {
    // Specify the drive letter of the USB drive you want to eject
    char driveLetter = 'F';
    
    // Get a list of process IDs
    DWORD pids[1024], bytesReturned;
    if (!EnumProcesses(pids, sizeof(pids), &bytesReturned)) {
        std::cerr << "Error enumerating processes" << std::endl;
        return 1;
    }

    // Find and close handles to files and folders opened by Explorer for the specified drive
    for (unsigned int i = 0; i < bytesReturned / sizeof(DWORD); i++) {
        DWORD pid = pids[i];
        if (pid == 0) continue;

        HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, pid);
        if (hProcess) {
            HANDLE hFile = nullptr;
            char filename[MAX_PATH];
            if (GetProcessImageFileNameA(hProcess, filename, MAX_PATH) > 0) {
                if (strlen(filename) >= 2 && filename[1] == ':') {
                    if (toupper(filename[0]) == toupper(driveLetter)) {
                        // Found a process with a handle to a file on the specified drive
                        std::cout << "Found and closing handle for process ID: " << pid << std::endl;
                        // Close the handle
                        CloseHandle(hProcess);
                    }
                }
            }
        }
    }

    return 0;
}
