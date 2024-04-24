#include <string.h>
#include <stdlib.h>

int good_data(char* buff) {
    char *ip_copy = strdup(buff); // Make a copy of the input string

    char *ip;
    ip = strtok (ip_copy, " ");
    ip = strtok (NULL, " ");
    ip = strtok (NULL, " ");
    ip = strtok (ip, ":");

    if(ip != NULL) {
        printf("IP: %s\n", ip);
        // Call a function with the IP address
        // function_using_ip(ip);
    }

    free(ip_copy); // Free the memory allocated by strdup

    return 0;
}
