#include <Windows.h>
#include <stdio.h>

int wmain()
{
    COMPUTER_NAME_FORMAT nameType = ComputerNameDnsFullyQualified;
    WCHAR computerName[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD size = MAX_COMPUTERNAME_LENGTH + 1;

    // Call GetComputerNameEx with null buffer to retrieve required size
    if (!GetComputerNameEx(nameType, NULL, &size))
    {
        DWORD error = GetLastError();
        wprintf(L"Error getting size. Code: %li\n", error);
        return 1;
    }

    // Call GetComputerNameEx again with the correct buffer size
    if (GetComputerNameEx(nameType, computerName, &size))
    {
        wprintf(L"Computer name: %s\n", computerName);
    }
    else
    {
        DWORD error = GetLastError();
        wprintf(L"Error getting the name. Code: %li\n", error);
    }

    return 0;
}
