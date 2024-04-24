#include <windows.h>
#include <stdio.h>

int wmain()
{
    COMPUTER_NAME_FORMAT nameType = ComputerNameDnsFullyQualified;
    WCHAR *computerName = NULL; // Pointer to computer name buffer
    DWORD size = 0; // Initial size is 0 to get the required buffer size

    // Get the required buffer size first
    BOOL pcName = GetComputerNameEx(nameType, NULL, &size);
    DWORD error = GetLastError();

    // Check if the buffer was too small
    if (!pcName && error == ERROR_MORE_DATA)
    {
        // Allocate memory for the computer name
        computerName = (WCHAR *)malloc(size * sizeof(WCHAR));
        if (!computerName)
        {
            wprintf(L"Error allocating memory for computer name.\n");
            return 1;
        }

        // Now get the actual computer name
        pcName = GetComputerNameEx(nameType, computerName, &size);
        error = GetLastError();
    }

    if (pcName)
    {
        wprintf(L"Computer name: %s\n", computerName);
        // Free the allocated memory
        free(computerName);
    }
    else
    {
        wprintf(L"Error getting the name. Code: %lu\n", error);
    }

    return 0;
}
