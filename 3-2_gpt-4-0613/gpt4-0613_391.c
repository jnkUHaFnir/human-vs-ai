
Main function (error checks added, using correct calls to WSASend/WSARecv):
```c++
int main(void)
{
    WSADATA WsaDat;
    if (WSAStartup(MAKEWORD(2,2),&WsaDat)!=0)
    {
        std::cout<<"Winsock error - Winsock initialization failed\r\n";
        return 0;
    }
    
    HANDLE hCompletionPort=CreateIoCompletionPort(INVALID_HANDLE_VALUE,NULL,0,0);
    if(!hCompletionPort)
    {
        std::cout<<"Winsock error - Failed to create completion port\r\n";
        WSACleanup();
        return 0;
    }

    SYSTEM_INFO systemInfo;
    GetSystemInfo(&systemInfo);

    for(int i=0;i<systemInfo.dwNumberOfProcessors;i++)
    {
        HANDLE hThread = CreateThread(NULL,0,ClientWorkerThread,hCompletionPort,0,NULL);
        CloseHandle(hThread);
    }

    SOCKET Socket=WSASocket(AF_INET,SOCK_STREAM,IPPROTO_TCP,NULL,0,WSA_FLAG_OVERLAPPED);
    if(Socket==INVALID_SOCKET)
    {
        std::cout<<"Winsock error - Socket creation failed\r\n";
        WSACleanup();
        return 0;
    }

    CreateIoCompletionPort((HANDLE)Socket,hCompletionPort,(ULONG_PTR)0,0);
    SOCKADDR_IN SockAddr;
    memset(&SockAddr,0,sizeof(SockAddr));
    SockAddr.sin_port=htons(8888);
    SockAddr.sin_family=AF_INET;
    SockAddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    
    if(WSAConnect(Socket,(SOCKADDR*)(&SockAddr),sizeof(SockAddr),NULL,NULL,NULL,NULL)==SOCKET_ERROR)
    {
        std::cout<<"Winsock error - Unable to connect\r\n";
        WSACleanup();
        return 0;
    }

    // ... then issue the first WSARecv or WSASend depending on your protocol
}
``` 

In `wsabuf.buf` you will always have very old data, because you are assigning it before the first asynchronous operation and you are not updating it after the completions. You should instead issue a new WSARecv each time you processed data from the server.

Of course, you'll need to design and implement a way to close everything down cleanly if your `WSARecv` fails synchronously or your server disconnects. In a more complete implementation, you'd want to look into things like having your socket and its associated data be in a struct that gets passed around with each completion.
