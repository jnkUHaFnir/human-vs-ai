#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool starts_with_post(const char *data) {
    return strncmp(data, "POST", 4) == 0;
}

int main() {
    // Simulating your scenario
    const char *data = "POST /path HTTP/1.1\r\nHost: example.com\r\n...";
    // Call the function to check if it starts with "POST"
    if (starts_with_post(data)) {
        // If it does, your code to handle POST packets goes here
        printf("This is a POST request.\n");
    } else {
        // If it doesn't, handle other cases
        printf("This is not a POST request.\n");
    }

    return 0;
}
