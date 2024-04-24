#include <Windows.h>
#include <ShObjIdl_core.h>
#include <atlbase.h>

bool CloseExplorerWindowsOnDrive(const wchar_t* driveLetter)
{
    CComPtr<IShellWindows> spShellWindows;
    if (SUCCEEDED(spShellWindows.CoCreateInstance(CLSID_ShellWindows)))
    {
        VARIANT vEmpty = {};
        long count = 0;
        if (SUCCEEDED(spShellWindows->get_Count(&count)))
        {
            for (long i = count - 1; i >= 0; i--)
            {
                CComPtr<IDispatch> spDispatch;
                if (SUCCEEDED(spShellWindows->Item(COleVariant(i), &spDispatch)))
                {
                    CComQIPtr<IWebBrowserApp> spBrowserApp(spDispatch);
                    if (spBrowserApp)
                    {
                        CComPtr<IShellBrowser> spBrowser;
                        if (SUCCEEDED(spBrowserApp->QueryInterface(IID_PPV_ARGS(&spBrowser))))
                        {
                            CComPtr<IShellView> spShellView;
                            if (SUCCEEDED(spBrowser->QueryActiveShellView(&spShellView)))
                            {
                                CComPtr<IFolderView> spFolderView;
                                if (SUCCEEDED(spShellView->QueryInterface(IID_PPV_ARGS(&spFolderView))))
                                {
                                    CComPtr<IPersistFolder2> spPersistFolder;
                                    if (SUCCEEDED(spFolderView->GetFolder(IID_PPV_ARGS(&spPersistFolder))))
                                    {
                                        LPITEMIDLIST pidl;
                                        if (SUCCEEDED(spPersistFolder->GetCurFolder(&pidl)) && pidl)
                                        {
                                            CComPtr<IShellItem> spShellItem;
                                            if (SUCCEEDED(SHCreateItemFromIDList(pidl, IID_PPV_ARGS(&spShellItem))))
                                            {
                                                PWSTR pszDrive;
                                                if (SUCCEEDED(spShellItem->GetDisplayName(SIGDN_FILESYSPATH, &pszDrive)))
                                                {
                                                    if (pszDrive[0] == driveLetter[0]) // Compare drive letters
                                                    {
                                                        HWND hwnd;
                                                        if (SUCCEEDED(spShellView->GetWindow(&hwnd)))
                                                        {
                                                            PostMessage(hwnd, WM_CLOSE, 0, 0); // Force close the Explorer window
                                                            CoTaskMemFree(pszDrive);
                                                            CoTaskMemFree(pidl);
                                                            return true;
                                                        }
                                                    }
                                                    CoTaskMemFree(pszDrive);
                                                }
                                            }
                                            CoTaskMemFree(pidl);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

int main()
{
    // Close any Windows Explorer windows opened on drive D:
    CloseExplorerWindowsOnDrive(L"D");

    return 0;
}
