#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <errno.h>

#define HOST "localhost"
#define PAGE "/"
#define PORT "80"
#define USERAGENT "HTML 1.1"

char *build_get_query(const char *host, const char *page) {
    char *query;
    const char *tpl = "GET /%s HTTP/1.1\r\nHost: %s\r\nUser-Agent: %s\r\nConnection: close\r\n\r\n";

    size_t query_len = strlen(host) + strlen(page) + strlen(USERAGENT) + strlen(tpl) - 6; // -6 for %s and \0
    query = (char *)malloc(query_len + 1); // +1 for the null terminator
    if (query == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    snprintf(query, query_len + 1, tpl, page, host, USERAGENT);

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
        fprintf(stderr, "\n\tUSAGE:\n\t%s hostname/ip PORTnr /PAGE/index.shtml \n\n", argv[0]);
        fprintf(stderr, "\texample:\n\t%s www.anypage.com 80 /folder/index.shtml \n\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = 0;
    hints.ai_protocol = 0;
    if ((s = getaddrinfo(argv[1], PORT, &hints, &servinfo)) != 0) {
        fprintf(stderr, "\n\tgetaddrinfo: %s\n", gai_strerror(s));
        exit(EXIT_FAILURE);
    }

    for (p = servinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("Socket creation failed");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("Connection failed");
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "Failed to establish connection\n");
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(servinfo);

    if (argc > 3) {
        page = argv[3];
    } else {
        page = PAGE;
    }

    stringA = build_get_query(argv[1], page);

    if (write(sockfd, stringA, strlen(stringA)) < 0) {
        perror("Error sending data");
    }

    memset(stringA, 0, strlen(stringA));

    while ((tmpres = read(sockfd, stringA, BUFSIZ)) > 0) {
        if ((sstr = strstr(stringA, "<!DOCTYPE ")) != NULL) {
            stringA = sstr;
        }
        if ((sstr = strstr(stringA, "</html>")) != NULL) {
            strncpy(sstr + 7, "\n", 1);
        }
        fprintf(stdout, "%s", stringA);
    }

    if (tmpres < 0) {
        perror("Error reading data");
    }

    close(sockfd);
    free(stringA); // Freeing the dynamically allocated memory
    return 0;
}
