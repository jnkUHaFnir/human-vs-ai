#include <Windows.h>
#include <stdio.h>

int wmain()
{
    COMPUTER_NAME_FORMAT nameType = ComputerNameDnsFullyQualified;
    WCHAR* computerName = NULL;
    DWORD size = 0;
    BOOL pcName = FALSE;

    // First call to get the required size of the buffer
    pcName = GetComputerNameEx(nameType, NULL, &size);
    if (pcName == 0)
    {
        wprintf(L"Error getting the name size. Code: %li\n", GetLastError());
        return 1;
    }

    computerName = (WCHAR*)malloc(size * sizeof(WCHAR));
    if (computerName == NULL)
    {
        wprintf(L"Memory allocation failed.\n");
        return 1;
    }

    // Second call to actually retrieve the computer name
    pcName = GetComputerNameEx(nameType, computerName, &size);
    if (pcName != 0)
    {
        wprintf("Computer name: %s\n", computerName);
    }
    else
    {
        wprintf(L"Error getting the name. Code: %li\n", GetLastError());
    }

    free(computerName);
    return 0;
}
