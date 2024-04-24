#include <Windows.h>
#include <stdio.h>

#pragma comment(lib, "Advapi32.lib") // Link the Advapi32 library

int main()
{
    COMPUTER_NAME_FORMAT nameType = ComputerNameDnsFullyQualified;
    WCHAR computerName[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD size = MAX_COMPUTERNAME_LENGTH + 1; // Initialize size with the size of computerName

    BOOL pcName = GetComputerNameEx(nameType, computerName, &size);

    DWORD error = GetLastError();

    if (pcName != 0)
    {
        wprintf(L"Computer name: %s\n", computerName);
    }
    else
    {
        if (error == ERROR_MORE_DATA) // Check if error is due to insufficient buffer
        {
            wprintf(L"Error: Insufficient buffer size. Required size: %d\n", size);
        }
        else
        {
            wprintf(L"Error getting the name. Code: %lu\n", error);
        }
    }

    return 0;
}
