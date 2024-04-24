#include <iostream>
#include <windows.h>
#include <string>

int main(int argc, char* argv[])
{
    if (argc > 1 && strncmp(argv[1], "sip:", 4) == 0)
    {
        std::string phoneNumber = std::string(argv[1] + 4); // Extract the phone number from the command line argument

        std::string cmd = "\"C:\\Program Files\\NCHSoftware\\Talk\\talk.exe\" -dial " + phoneNumber;
        // CreateProcess variables
        STARTUPINFO si;
        PROCESS_INFORMATION pi;

        ZeroMemory(&si, sizeof(si));
        si.cb = sizeof(si);
        ZeroMemory(&pi, sizeof(pi));

        // Start the program using CreateProcess
        if (!CreateProcess(NULL, const_cast<char*>(cmd.c_str()), NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
        {
            std::cerr << "Failed to execute talk.exe. Error code: " << GetLastError() << std::endl;
            return 1;
        }

        // Wait for the program to finish
        WaitForSingleObject(pi.hProcess, INFINITE);

        // Close process and thread handles
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }
    else
    {
        std::cerr << "Invalid command line argument. Usage: dial.exe sip:phoneNumber" << std::endl;
        return 1;
    }

    return 0;
}
