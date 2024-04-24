#include <windows.h>
#include <stdio.h>

int wmain()
{
    COMPUTER_NAME_FORMAT nameType = ComputerNameDnsFullyQualified;
    WCHAR* computerName = NULL;
    DWORD size = 0;

    // First call to get the required size of the computer name
    GetComputerNameEx(nameType, NULL, &size);

    if (size == 0)
    {
        wprintf(L"Error getting the size of the computer name. Code: %lu\n", GetLastError());
        return 1;
    }

    computerName = (WCHAR*)malloc(size * sizeof(WCHAR));
    if (computerName == NULL)
    {
        wprintf(L"Memory allocation failed.\n");
        return 1;
    }

    // Second call to actually retrieve the computer name
    if (!GetComputerNameEx(nameType, computerName, &size))
    {
        wprintf(L"Error getting the computer name. Code: %lu\n", GetLastError());
    }
    else
    {
        wprintf(L"Computer name: %s\n", computerName);
    }

    free(computerName);
    return 0;
}
