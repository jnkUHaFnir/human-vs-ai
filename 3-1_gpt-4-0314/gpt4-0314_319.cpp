#include <Windows.h>
#include <stdio.h>

int wmain()
{
    COMPUTER_NAME_FORMAT nameType = ComputerNameDnsFullyQualified;
    WCHAR* computerName = NULL;
    DWORD size = 0;

    // Get the required buffer size by setting the size to 0
    BOOL pcName = GetComputerNameEx(nameType, computerName, &size);
    DWORD error = GetLastError();

    if (error == ERROR_MORE_DATA)
    {
        // Allocate a larger buffer for the computer name
        computerName = (WCHAR*)malloc(size * sizeof(WCHAR));

        // Call the function again with the larger buffer
        pcName = GetComputerNameEx(nameType, computerName, &size);
        error = GetLastError();
    }

    if (pcName != 0)
    {
        wprintf(L"Computer name: %s\n", computerName);
    }
    else
    {
        wprintf(L"Error getting the name. Code: %li\n", error);
    }

    // Free the allocated memory for computerName
    if (computerName != NULL)
    {
        free(computerName);
    }

    return 0;
}

