#include <Windows.h>
#include <stdio.h>

int wmain()
{
    COMPUTER_NAME_FORMAT nameType = ComputerNameDnsFullyQualified;
    WCHAR* computerName = NULL;
    DWORD size = 0; // Initial buffer size

    // First call to get the required size
    BOOL pcName = GetComputerNameEx(nameType, NULL, &size);

    DWORD error = GetLastError();
    if (!pcName && (error == ERROR_MORE_DATA))
    {
        // Allocate buffer of the required size
        computerName = (WCHAR*)malloc(size * sizeof(WCHAR));
        if (computerName == NULL)
        {
            wprintf(L"Failed to allocate memory\n");
            return 1;
        }

        // Second call to actually get the computer name
        if (!GetComputerNameEx(nameType, computerName, &size))
        {
            error = GetLastError();
            wprintf(L"Error getting the name. Code: %lu\n", error);
            free(computerName);
            return 1;
        }

        wprintf(L"Computer name: %s\n", computerName);
        free(computerName); // Don't forget to free the memory
    }
    else if (pcName)
    {
        wprintf(L"Unexpected success without requiring buffer size.\n");
    }
    else
    {
        wprintf(L"Error getting the name. Code: %lu\n", error);
    }

    return 0;
}
