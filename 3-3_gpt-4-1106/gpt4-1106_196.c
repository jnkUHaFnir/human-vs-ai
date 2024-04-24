int attempt_connection_with_timeout(int sock, const struct sockaddr *addr, socklen_t addrlen) {
    // Set the socket non-blocking
    int flags = fcntl(sock, F_GETFL, 0);
    fcntl(sock, F_SETFL, flags | O_NONBLOCK);
    
    // Start connection
    int res = connect(sock, addr, addrlen);
    if (res < 0 && errno == EINPROGRESS) {
        // Connection is in progress
        struct timeval tv;
        tv.tv_sec = 1;   // Wait at most 1 second
        tv.tv_usec = 0;
        
        fd_set wfds;
        FD_ZERO(&wfds);
        FD_SET(sock, &wfds);
        
        res = select(sock + 1, NULL, &wfds, NULL, &tv);
        if (res > 0) {
            // Socket is writable, hence the connection succeeded
            // Restore the socket flags
            fcntl(sock, F_SETFL, flags);
            return 0;
        }
    }
    // Connection failed or timed out
    return -1;
}