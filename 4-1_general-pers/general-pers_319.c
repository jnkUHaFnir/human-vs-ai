#include <Windows.h>
#include <cstdio>

int wmain()
{
    COMPUTER_NAME_FORMAT nameType = ComputerNameDnsFullyQualified;
    WCHAR computerName[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD size = MAX_COMPUTERNAME_LENGTH + 1; // Set initial size to maximum possible length

    BOOL pcName = GetComputerNameEx(nameType, computerName, &size);

    DWORD error = GetLastError();

    if (pcName != 0)
    {
        if (size <= MAX_COMPUTERNAME_LENGTH)
        {
            wprintf(L"Computer name: %s\n", computerName);
        }
        else
        {
            wprintf(L"Buffer too small to hold computer name.\n");
        }
    }
    else
    {
        wprintf(L"Error getting the name. Code: %li\n", error);
    }

    return 0;
}
