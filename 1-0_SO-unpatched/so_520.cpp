    #include <Windows.h>
    #include <iostream>
    using namespace std;
    
    typedef struct _SYSTEM_HANDLE_INFORMATION
    {
        ULONG ProcessId; 
        UCHAR ObjectTypeNumber;
        UCHAR Flags;
        USHORT Handle;
        PVOID Object;
        ACCESS_MASK GrantedAccess;
    }SYSTEM_HANDLE_INFORMATION, * PSYSTEM_HANDLE_INFORMATION;
    
    typedef struct _SYSTEM_HANDLE_INFORMATION_EX
    {
        ULONG NumberOfHandles;
        SYSTEM_HANDLE_INFORMATION Information[655360];//This is the size I defined myself
    }SYSTEM_HANDLE_INFORMATION_EX, * PSYSTEM_HANDLE_INFORMATION_EX;
    
    #define SystemHandleInformation 0x10
    
    typedef NTSTATUS(WINAPI* NTQUERYSYSTEMINFORMATION)(DWORD, PVOID, DWORD, PDWORD);
    
    int main()
    {
        HMODULE hNtDll = LoadLibraryW(L"ntdll.dll");
        NTQUERYSYSTEMINFORMATION NtQuerySystemInformation = (NTQUERYSYSTEMINFORMATION)GetProcAddress(hNtDll, "NtQuerySystemInformation");
        ULONG cbBuffer = sizeof(SYSTEM_HANDLE_INFORMATION_EX);
        LPVOID pBuffer = (LPVOID)malloc(cbBuffer);
        if (pBuffer)
        {
            NTSTATUS  status = NtQuerySystemInformation(SystemHandleInformation, pBuffer, cbBuffer, NULL);
            PSYSTEM_HANDLE_INFORMATION_EX pInfo = (PSYSTEM_HANDLE_INFORMATION_EX)pBuffer;
            DWORD pid = 0;
            int err = 0;
            for (ULONG r = 0; r < pInfo->NumberOfHandles; r++)
            {
                if (pInfo->Information[r].Handle is the handle you want)
                {
                    if ((pid = GetProcessId((HANDLE)pInfo->Information[r].Handle)) == 0)
                    {
                        err = GetLastError();
                        cout << "The 1st GetProcessId error : " << err << endl;
                    }
                    HANDLE hProcess = OpenProcess(PROCESS_DUP_HANDLE,false, pInfo->Information[r].ProcessId);
                    HANDLE hTarget;
                    if (!DuplicateHandle(hProcess, (HANDLE)pInfo->Information[r].Handle, ::GetCurrentProcess(), &hTarget, 0, FALSE, DUPLICATE_SAME_ACCESS))
                    {
                        err = GetLastError();
                        cout << "DuplicateHandle error : " << err << endl;
                        return -1;
                    }
                    if ((pid = GetProcessId(hTarget))==0)
                    {
                        err = GetLastError();
                        cout << "GetProcessId error : " << err << endl;
                        return -1;
                    }
                    cout << "The 2nd GetProcessId succeed, " <<  "ProcessId =  " << pid << endl;
                }
                    
            }
    
            free(pBuffer);
        }
        FreeModule(hNtDll);
        getchar();
    }