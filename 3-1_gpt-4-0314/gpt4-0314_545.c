char *build_get_query(char *host, char *page, char *query) {
    char *getpage = page;
    char *tpl = "GET /%s HTTP/1.1\r\nHost: %s\r\nUser-Agent: %s\r\nConnection: close\r\n\r\n";

    if (getpage[0] == '/') {
        getpage = getpage + 1; /* Removing leading / */
    }
    /* -5 is to consider the %s %s %s in tpl and the ending \0 */
    sprintf(query, tpl, getpage, host, USERAGENT);

    return query;
}

// ...

int main(int argc, char **argv) {
    // ... other parts remain the same

    if ((stringA = malloc(BUFSIZ)) == NULL) {
        printf("\n\tMEMORY ERROR\n\n");
        exit(1);
    }
    build_get_query(argv[1], page, stringA);
    if ((write(sockfd, stringA, strlen(stringA))) < 0) {
        printf("\n\tERROR ON SEND\n\n");
    }
    memset(stringA, 0, sizeof(stringA));

    // ...

    free(stringA); // Add this line to free memory before exiting
    close(sockfd);
    return 0;
}
