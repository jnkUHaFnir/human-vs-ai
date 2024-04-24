#include <Windows.h>
#include <winternl.h>

typedef struct _OBJECT_BASIC_INFORMATION {
    ULONG Attributes;
    ACCESS_MASK GrantedAccess;
    ULONG HandleCount;
    ULONG PointerCount;
    ULONG PagedPoolUsage;
    ULONG NonPagedPoolUsage;
    ULONG Reserved[3];
    ULONG NameInformationLength;
    ULONG TypeInformationLength;
    ULONG SecurityDescriptorLength;
    LARGE_INTEGER CreateTime;
} OBJECT_BASIC_INFORMATION;

typedef NTSTATUS
(NTAPI* pfnNtQueryObject)(
    HANDLE ObjectHandle,
    OBJECT_INFORMATION_CLASS ObjectInformationClass,
    PVOID ObjectInformation,
    ULONG ObjectInformationLength,
    PULONG ReturnLength
);

int GetProcessIdFromHandle(HANDLE hHandle) {
    pfnNtQueryObject NtQueryObject = (pfnNtQueryObject)GetProcAddress(GetModuleHandle("ntdll.dll"), "NtQueryObject");
    
    if (NtQueryObject == NULL) {
        return 0;
    }

    OBJECT_BASIC_INFORMATION objInfo;
    ULONG returnLength;

    NTSTATUS status = NtQueryObject(hHandle, ObjectBasicInformation, &objInfo, sizeof(objInfo), &returnLength);

    if (NT_SUCCESS(status)) {
        return PtrToUlong(objInfo.UniqueProcessId);
    }

    return 0;
}
