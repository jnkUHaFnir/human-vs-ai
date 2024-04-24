#include <Windows.h>
#include <stdio.h>

int wmain()
{
    COMPUTER_NAME_FORMAT nameType = ComputerNameDnsFullyQualified;
    WCHAR computerName[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD size = sizeof(computerName) / sizeof(computerName[0]); // Initialize size to maximum

    BOOL pcName = GetComputerNameEx(nameType, computerName, &size);

    DWORD error = GetLastError();

    if (pcName != 0)
    {
        wprintf(L"Computer name: %s\n", computerName);
    }
    else
    {
        if (error == ERROR_MORE_DATA) // Check if the error is "More data is available"
        {
            // Increase size and try again
            computerName[size - 1] = L'\0'; // Set the last character as null terminator
            pcName = GetComputerNameEx(nameType, computerName, &size);

            if (pcName != 0)
            {
                wprintf(L"Computer name: %s\n", computerName);
            }
            else
            {
                error = GetLastError();
                wprintf(L"Error getting the name. Code: %li\n", error);
            }
        }
        else
        {
            wprintf(L"Error getting the name. Code: %li\n", error);
        }
    }

    return 0;
}
