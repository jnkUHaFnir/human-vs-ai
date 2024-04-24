#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

#define HOST "localhost"
#define PAGE "/"
#define PORT "80"
#define USERAGENT "HTML 1.1"

char *build_get_query(char *host, char *page) {
    char *query;
    char *tpl = "GET /%s HTTP/1.1\r\nHost: %s\r\nUser-Agent: %s\r\nConnection: close\r\n\r\n";

    if (page[0] == '/') {
        page = page + 1; /* Removing leading / */
    }
    /* Calculate length needed for the query */
    int len = snprintf(NULL, 0, tpl, page, host, USERAGENT);
    query = malloc(len + 1); // +1 for the null terminator
    if (query == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    sprintf(query, tpl, page, host, USERAGENT);

    return query;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s hostname/ip [PORTnr] [/PAGE/index.shtml]\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Rest of your main function code as it is

    char *stringA = malloc(BUFSIZ);
    if (stringA == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }
    
    char *query = build_get_query(argv[1], (argc > 3) ? argv[3] : PAGE);

    // Use strncpy instead of direct assignment
    strncpy(stringA, query, BUFSIZ);

    // Free the dynamically allocated memory
    free(query);

    // Continue with the rest of your program

    free(stringA); // Free the memory allocated for stringA

    return EXIT_SUCCESS;
}
