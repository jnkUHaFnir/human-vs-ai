char *build_get_query(char *host, char *page) {
    char *query;
    char *getpage = page;
    char *tpl = "GET /%s HTTP/1.1\r\nHost: %s\r\nUser-Agent: %s\r\nConnection: close\r\n\r\n";

    if (getpage[0] == '/') {
        getpage = getpage + 1; /* Removing leading / */
    }
    
    // Calculate the required buffer size for the query
    int query_len = snprintf(NULL, 0, tpl, getpage, host, USERAGENT) + 1;
    
    query = malloc(query_len);
    if (query == NULL) {
        fprintf(stderr, "\n\tMEMORY ERROR\n\n");
        exit(1);
    }

    sprintf(query, tpl, getpage, host, USERAGENT);

    return query;
}
