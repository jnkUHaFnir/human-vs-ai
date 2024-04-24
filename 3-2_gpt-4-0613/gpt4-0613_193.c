    fcntl(mySock, F_SETFL, O_NONBLOCK); 
    int res = connect(mySock, addr, addrlen);
    if ((res < 0) && (errno == EINPROGRESS)) {
        struct timeval tv; 
        fd_set writefds;

        tv.tv_sec = 1;  // Timeout after one second
        tv.tv_usec = 0;

        FD_ZERO(&writefds);
        FD_SET(mySock, &writefds); 

        if (select(mySock+1, NULL, &writefds, NULL, &tv) > 0) {
            int val; 
            socklen_t lon; 

            lon = sizeof(int);
            getsockopt(mySock, SOL_SOCKET, SO_ERROR, &(val), &lon);
            if (val == 0) {
                // Connected!
            }
        }
        else {
            // Timeout or error.
        }
    }
