#include <stdio.h>
#include <string.h>

int main() {
    char re[1000];
    strncpy(re, data, 1000);  // Assuming size_data is the maximum buffer size
    int len = strlen(re);

    const char *post = "POST";
    int post_len = strlen(post);

    // Check if the packet starts with "POST"
    if (len >= post_len && strncmp(re, post, post_len) == 0) {
        // Packet starts with "POST", do something
        printf("Packet starts with POST\n");
    } else {
        // Packet does not start with "POST"
        printf("No POST method found in packet\n");
    }

    return 0;
}
