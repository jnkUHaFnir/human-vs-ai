HWND hwnd = FindWindow(NULL, L"FolderName - Windows Explorer");
if(hwnd != NULL)
{
    SendMessage(hwnd, WM_CLOSE, 0, 0);
}

Of course, killing Explorer windows in this way is a pretty invasive operation and could easily lead to data loss if the user was in the middle of something. A better solution would be for your application to communicate to the user that the drive cannot be ejected until all open files and folders are closed, and allow them to take the appropriate action.
