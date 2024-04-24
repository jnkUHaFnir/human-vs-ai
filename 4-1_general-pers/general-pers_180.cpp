#include <iostream>
#include <windows.h>
#include <string>

int main(int argc, char* argv[])
{
    if (argc > 1 && strncmp(argv[1], "sip:", 4) == 0)
    {
        std::string command = "C:\\Program Files\\NCHSoftware\\Talk\\talk.exe -dial " + std::string(argv[1] + 4);
        STARTUPINFO si;
        PROCESS_INFORMATION pi;

        ZeroMemory(&si, sizeof(si));
        si.cb = sizeof(si);
        ZeroMemory(&pi, sizeof(pi));

        if (!CreateProcess(NULL, const_cast<char*>(command.c_str()), NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
        {
            std::cerr << "Error creating process. Error code: " << GetLastError() << std::endl;
            return 1;
        }

        WaitForSingleObject(pi.hProcess, INFINITE);

        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }
    else
    {
        std::cerr << "Invalid arguments. Usage: dial.exe sip:<phone_number>" << std::endl;
        return 1;
    }

    return 0;
}
