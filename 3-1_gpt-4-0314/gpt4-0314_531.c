    // ...
    while (bytesRec > 0)
    {
        memset(buf, 0, BUFSIZE);
        bytesRec = recv(clientSocket, buf, BUFSIZE, 0);
        //...
    }
    for (;;)
    {
        // ...
        memset(serverReply, 0, sizeof(serverReply));
        int bytesRead = recv(clientSocket, serverReply, 1024, 0);
        if (bytesRead < 0)
        {
            printf("failure in receiving from server!\n");
        }
        else
        {
            serverReply[bytesRead] = '\0';
            printf("%s\n", serverReply);
        }
    }
