#include <Windows.h>
#include <stdio.h>

#define MAX_COMPUTERNAME_LENGTH 256

int wmain()
{
    COMPUTER_NAME_FORMAT nameType = ComputerNameDnsFullyQualified;
    WCHAR computerName[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD size = MAX_COMPUTERNAME_LENGTH + 1; // Initialize size with buffer size

    BOOL pcName = GetComputerNameEx(nameType, computerName, &size);

    DWORD error = GetLastError();

    if (pcName != 0)
    {
        wprintf(L"Computer name: %s\n", computerName);
    }
    else
    {
        if (error == ERROR_MORE_DATA)
        {
            wprintf(L"Buffer too small for computer name.\n");
        }
        else
        {
            wprintf(L"Error getting the name. Code: %li\n", error);
        }
    }

    return 0;
}
