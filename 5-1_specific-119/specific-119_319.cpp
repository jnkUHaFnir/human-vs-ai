#include <Windows.h>
#include <stdio.h>

int wmain()
{
    COMPUTER_NAME_FORMAT nameType = ComputerNameDnsFullyQualified;
    WCHAR computerName[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD size = MAX_COMPUTERNAME_LENGTH + 1;

    BOOL pcName = GetComputerNameEx(nameType, computerName, &size);

    DWORD error = GetLastError();

    if (!pcName)
    {
        if (error == ERROR_MORE_DATA)
        {
            // Retry with a larger buffer
            WCHAR* largerComputerName = new WCHAR[size];
            pcName = GetComputerNameEx(nameType, largerComputerName, &size);

            if (pcName)
            {
                wprintf("Computer name: %s\n", largerComputerName);
            }
            else
            {
                error = GetLastError();
                wprintf(L"Error getting the name. Code: %li\n", error);
            }

            delete[] largerComputerName;
        }
        else
        {
            wprintf(L"Error getting the name. Code: %li\n", error);
        }
    }
    else
    {
        wprintf("Computer name: %s\n", computerName);
    }

    return 0;
}
