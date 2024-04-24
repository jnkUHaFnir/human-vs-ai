    char pathText[64] = "./dir/prefix";  // a buffer of text with path using dot (.) for current dir
    char *pFile = strrchr (pathText, '/');  // find last slash where the file name begins
    char *pExt = strrchr (pathText, '.');    // looking for file extension 
    
    // at this point the programmer expected that
    //   - pFile points to the last slash in the path name
    //   - pExt point to the dot (.) in the file extension or NULL
    // however with this data we instead have the following pointers because rather than
    // an absolute path, it is a relative path
    //   - pFile points to the last slash in the path name
    //   - pExt point to the first dot (.) in the path name as there is no file extension
    // the result is that rather than a non-NULL pExt value being larger than pFile,
    // it is instead smaller for this specific data.
    char *pNameNoExt;
    if (pExt) {  // this really should be if (pExt && pFile < pExt) {
        // extension specified so allocate space just for the name, no extension
        // allocate space for just the file name without the extension
        // since pExt is less than pFile, we get a negative value which then becomes
        // a really huge unsigned value.
        pNameNoExt = malloc ((pExt - pFile + 1) * sizeof(char));
    } else {
        pNameNoExt = malloc ((strlen(pFile) + 1) * sizeof(char));
    }