int wmain()
{
    COMPUTER_NAME_FORMAT nameType = ComputerNameDnsFullyQualified;
    WCHAR computerName[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD size = MAX_COMPUTERNAME_LENGTH + 1; // Set initial size value

    BOOL pcName = GetComputerNameEx(nameType, computerName, &size);

    DWORD error = GetLastError();

    if (pcName != 0)
    {
        wprintf(L"Computer name: %s\n", computerName);
    }
    else
    {
        if (error == ERROR_MORE_DATA)
        {
            // If the error is due to insufficient buffer size, resize the buffer and try again
            size += 1; // Increase the size by 1
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
