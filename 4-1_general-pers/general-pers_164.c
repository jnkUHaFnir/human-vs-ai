#include <stdio.h>
#include <string.h>

void filterHttpPost(char *data, size_t size_data) {
    if (size_data >= 5 && strncmp(data, "POST ", 5) == 0) {
        // Process the packet as a POST request
        printf("Found a POST request!\n");
        // *something happens*
    }
}

int main() {
    char data[] = "POST /example HTTP/1.1\r\nHost: example.com\r\nContent-Length: 10\r\n\r\nHello"; // Example packet data
    size_t size_data = strlen(data);

    // Filter HTTP packets by POST method
    filterHttpPost(data, size_data);

    return 0;
}
