int wmain()
{
    COMPUTER_NAME_FORMAT nameType = ComputerNameDnsFullyQualified;
    WCHAR computerName[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD size = ARRAYSIZE(computerName);

    BOOL pcName = GetComputerNameEx(nameType, computerName, &size); // pass the address of the size variable

    DWORD error = GetLastError();

    if (pcName != 0)
    {
        wprintf("Computer name: %s\n", computerName);
    }
    else
    {
        if (error == ERROR_MORE_DATA) 
        {
            // If the buffer size is insufficient, allocate a larger buffer and try again
            WCHAR* dynamicComputerName = new WCHAR[size];
            pcName = GetComputerNameEx(nameType, dynamicComputerName, &size);
            if (pcName != 0) 
            {
                wprintf("Computer name: %s\n", dynamicComputerName);
                delete[] dynamicComputerName; // don't forget to free the allocated memory
            }
            else 
            {
                wprintf(L"Error getting the name. Code: %li\n", GetLastError());
            }
        }
        else 
        {
            wprintf(L"Error getting the name. Code: %li\n", error);
        }
    }

    return 0;
}
