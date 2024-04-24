    LONG error = ERROR_MORE_DATA;
    WCHAR* buffer = NULL;
    DWORD bufferLength = /* Some initial reasonable length for the string buffer */;
    while (error == ERROR_MORE_DATA)
    {
        if (buffer != NULL) free(buffer);
        // Create a buffer with bufferLength size (measured in WCHARs)
        buffer = malloc(bufferLength * sizeof(WCHAR));
        error = GetComputerNameEx(nameType, buffer, &bufferLength);
    }
    if (error != ERROR_SUCCESS)
    {
        // Some error occurred
        ...
    }
    // Use buffer comtaining computer name
    // Don't forget to free(buffer)