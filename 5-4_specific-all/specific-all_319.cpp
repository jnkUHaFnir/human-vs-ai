#include <Windows.h>
#include <stdio.h>

int wmain()
{
    COMPUTER_NAME_FORMAT nameType = ComputerNameDnsFullyQualified;
    WCHAR computerName[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD size = 0;

    // Retrieve the required size for the computer name
    GetComputerNameEx(nameType, NULL, &size);

    // Allocate memory dynamically for the computer name
    WCHAR* dynamicComputerName = new WCHAR[size];

    BOOL pcName = GetComputerNameEx(nameType, dynamicComputerName, &size);
    DWORD error = GetLastError();

    if (pcName != 0)
    {
        wprintf(L"Computer name: %s\n", dynamicComputerName);
    }
    else
    {
        wprintf(L"Error getting the name. Code: %li\n", error);
    }

    delete[] dynamicComputerName; // Don't forget to free the allocated memory

    return 0;
}
