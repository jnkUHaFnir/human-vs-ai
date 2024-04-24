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
#include <termios.h>

#define HOST "localhost"
#define PAGE "/"
#define PORT "80"
#define USERAGENT "HTML 1.1"

char *build_get_query(char *host, char *page) {
    char *query;
    char *getpage = page;
    char *tpl = "GET /%s HTTP/1.1\r\nHost: %s\r\nUser-Agent: %s\r\nConnection: close\r\n\r\n";

    if (getpage[0] == '/') {
        getpage = getpage + 1; /* Removing leading / */
    }

    query = malloc(strlen(host) + strlen(getpage) + strlen(USERAGENT) + strlen(tpl) - 6); // Adjusted length

    if (query == NULL) {
        fprintf(stderr, "\n\tMEMORY ERROR\n\n");
        exit(1);
    }

    sprintf(query, tpl, getpage, host, USERAGENT);

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
        fprintf(stderr, "\n\tUSAGE:\n\t%s hostname PORTnr /PAGE/index.shtml \n\n", argv[0]);
        fprintf(stderr, "\texample:\n\t%s www.anypage.com 80 /folder/index.shtml \n\n", argv[0]);
        exit(1);
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
            fprintf(stderr, "\n\tSOCKET FAIL\n\n");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) < 0) {
            close(sockfd);
            fprintf(stderr, "\n\tCONNECTION FAIL\n\n");
            continue;
        }
        break;
    }

    if (p == NULL) {
        fprintf(stderr, "\n\tCONNECTION FAIL\n\n");
        exit(2);
    }

    freeaddrinfo(servinfo);

    page = (argc > 3) ? argv[3] : PAGE;

    if ((stringA = malloc(BUFSIZ)) == NULL) {
        fprintf(stderr, "\n\tMEMORY ERROR\n\n");
        exit(1);
    }

    char *query = build_get_query(argv[1], page);
    
    if (write(sockfd, query, strlen(query)) < 0) {
        fprintf(stderr, "\n\tERROR ON SEND\n\n");
    }

    free(query); // Free the query after sending

    while ((tmpres = read(sockfd, stringA, BUFSIZ)) > 0) {
        if ((sstr = strstr(stringA, "<!DOCTYPE ")) != NULL) {
            stringA = sstr;
        }
        if ((sstr = strstr(stringA, "</html>")) != NULL) {
            strncpy(sstr + 7, "\n", BUFSIZ - (sstr - stringA) + 5);
        }
        fprintf(stdout, "%s", stringA);
    }

    if (tmpres < 0) {
        perror("READ ERROR");
    }

    close(sockfd);
    free(stringA); // Free the allocated memory before exiting
    return 0;
}
