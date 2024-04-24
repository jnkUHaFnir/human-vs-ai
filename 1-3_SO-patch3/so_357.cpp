    const char*  process_http(int sockfd, const char *host, const char *page, const char *poststr)
    {
        ....
        delete  []page, poststr,sendline,host,ptr;
        return response; // n
    }