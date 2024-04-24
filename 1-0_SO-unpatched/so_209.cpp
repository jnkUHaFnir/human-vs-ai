    WSAEVENT ev[1] = {WSACreateEvent()};
    memset(&over, 0, sizeof(over));
    over.hEvent = ev[0];
    if(AcceptEx(AcceptorSock, newSock, lpOutputBuf, outBufLen - ((sizeof(sockaddr_in) + 16) * 2), sizeof(sockaddr_in)+16, sizeof(sockaddr_in)+16, &dwBytes, &over) == FALSE)
    {
      int x = WSAGetLastError();
      if (x != ERROR_IO_PENDING)
      {
        ErrorAbort("Could not acceptex a new connection");
      }
      else
      {
        do
        {
          // On WSAWaitForMultipleEvents:
          // 1: Num of Event to wait for.
          // ev: array of events.
          // FALSE: Wait for all the events (if you are listening more than one event).
          // 100: Time out (milliseconds) is this time expires WSA_WAIT_TIMEOUT is returned.
          // For more details read: http://msdn.microsoft.com/en-us/library/ms742219%28VS.85%29.aspx
          DWORD dwWaitResult = WSAWaitForMultipleEvents(1, ev, FALSE, 100, FALSE);
          if (dwWaitResult == WSA_WAIT_EVENT_0)
          {
            cout << "There is a new connection with data" << endl;
            // Unsignal the event:
            WSAResetEvent(EventArray[dwWaitResult - WSA_WAIT_EVENT_0]);
            // Get the result of the operatio:
            WSAGetOverlappedResult(AcceptSocket, &AcceptOverlapped, &BytesTransferred, FALSE, &Flags);				
          }
          else
          {
            cerr << "Error Waiting For Event" << endl;
          }
        }while(dwWaitResult == WSA_WAIT_EVENT_0);
      }
    }