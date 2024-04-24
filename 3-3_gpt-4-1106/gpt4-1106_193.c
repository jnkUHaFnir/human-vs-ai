struct timeval tv;
tv.tv_sec = 1;  // 1 second timeout
tv.tv_usec = 0; // 0 microseconds

// set receive and send timeout for a socket
setsockopt(mySock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof(tv));
setsockopt(mySock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof(tv));
