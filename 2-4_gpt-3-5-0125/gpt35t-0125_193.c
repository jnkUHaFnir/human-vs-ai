if ((mySock = socket(servinfo[0]->ai_family, 
        servinfo[0]->ai_socktype | SOCK_NONBLOCK, servinfo[0]->ai_protocol)) == -1)
    sendErr("Socket() failed");
