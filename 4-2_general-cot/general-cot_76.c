#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int good_data(char* buff) {
    char *token;
    char *ip;
    char ip_copy[16]; // Assuming IPv4 addresses, 15 characters + null terminator
    
    // Make a copy of the buffer
    char buff_copy[strlen(buff) + 1]; // +1 for null terminator
    strcpy(buff_copy, buff);

    token = strtok(buff_copy, " ");
    token = strtok(NULL, " ");
    token = strtok(NULL, " ");
    ip = strtok(NULL, ":");
    if(ip == NULL) {
        return 0; // IP address not found
    }

    strncpy(ip_copy, ip, sizeof(ip_copy)-1);
    ip_copy[sizeof(ip_copy)-1] = '\0';

    printf("IP below\n");
    printf("%s\n", ip_copy);

    // Now you can use ip_copy for further processing or comparisons

    return 0;
}
