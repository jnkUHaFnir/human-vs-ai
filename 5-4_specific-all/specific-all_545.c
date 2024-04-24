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
        getpage = getpage + 1; /*Removing leading / */
    }

    query = malloc(strlen(host) + strlen(getpage) + strlen(USERAGENT) + strlen(tpl) - 5);
    sprintf(query, tpl, getpage, host, USERAGENT);

    return query;
}

int main(int argc, char **argv) {
    int sockfd;
    // variable declarations

    char *page;
    char *stringA;
    int tmpres;
    char *sstr;

    // argument checking

    // socket initialization

    if (argc > 3) {
        page = argv[3];
    } else {
        page = PAGE;
    }

    if ((stringA = malloc(BUFSIZ)) == NULL) {
        printf("\n\tMEMORY ERROR\n\n");
        exit(1);
    }
    
    char *query = build_get_query(argv[1], page);
    strcpy(stringA, query); // Copy the content of query to stringA
    free(query); // Free the allocated query memory

    if (write(sockfd, stringA, strlen(stringA)) < 0) {
        printf("\n\tERROR ON SEND\n\n");
    }

    free(stringA); // Free the allocated stringA memory after its usage

    // receiving and printing webpage content

    // cleaning up and closing socket

    return 0;
}

