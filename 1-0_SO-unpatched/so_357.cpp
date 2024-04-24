    const char*  process_http(int sockfd, const char *host, const char *page, const char *poststr)
    {
        ....
        // delete here only what you dynamically 
        // allocated with new() BEFORE the return
        return response; // n
    }