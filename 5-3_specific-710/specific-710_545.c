#define _XOPEN_SOURCE 600
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>

#define HOST "localhost"
#define PAGE "/"
#define PORT "80"
#define USERAGENT "HTML 1.1"

char *build_get_query(char *host, char *page) {
    if (page[0] == '/') {
        page = page + 1; /* Removing leading / */
    }

    // Allocate memory for the query with a proper size based on the lengths of host, page, and USERAGENT
    char *query;
    size_t query_size = strlen(page) + strlen(host) + strlen(USERAGENT) + strlen("GET HTTP/1.1\r\nHost: \r\nUser-Agent: \r\nConnection: close\r\n\r\n") + 1;
    query = malloc(query_size);
    if (query == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Construct the query string
    sprintf(query, "GET /%s HTTP/1.1\r\nHost: %s\r\nUser-Agent: %s\r\nConnection: close\r\n\r\n", page, host, USERAGENT);
    
    return query;
}

int main(int argc, char **argv) {
    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    int s;

    char *page;
    char *stringA;
    int tmpres;
    char *sstr;

    if (argc < 4) {
        fprintf(stderr, "USAGE: %s hostname/ip PORTnr /PAGE/index.shtml\n", argv[0]);
        fprintf(stderr, "Example: %s www.anypage.com 80 /folder/index.shtml\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    
    if ((s = getaddrinfo(argv[1], PORT, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
        exit(EXIT_FAILURE);
    }

    for (p = servinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("connect");
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "Failed to connect\n");
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(servinfo);

    page = (argc > 3) ? argv[3] : PAGE;

    stringA = build_get_query(argv[1], page);
    if (write(sockfd, stringA, strlen(stringA)) < 0) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    memset(stringA, 0, strlen(stringA)); // Clearing the memory properly

    while ((tmpres = read(sockfd, stringA, BUFSIZ)) > 0) {
        if ((sstr = strstr(stringA, "<!DOCTYPE ")) != NULL) {
            stringA = sstr;
        }
        if ((sstr = strstr(stringA, "</html>")) != NULL) {
            strncpy(sstr+7, "\n", (BUFSIZ - (sstr - stringA)) + 5);
        }
        fprintf(stdout, "%s", stringA);

        memset(stringA, 0, tmpres); // Clearing the memory properly for next read
    }

    if (tmpres < 0) {
        perror("read");
    }

    close(sockfd);
    free(stringA); // Freeing the allocated memory

    return 0;
}
