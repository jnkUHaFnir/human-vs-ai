#include <stdio.h>
#include <string.h>

// Assuming MAX_METHOD_LENGTH is the maximum length of an HTTP method like "POST"
#define MAX_METHOD_LENGTH 10

void processPacket(char *data, size_t size_data) {
    char method[MAX_METHOD_LENGTH];
    
    // Copy the first MAX_METHOD_LENGTH characters from data to method
    strncpy(method, data, MAX_METHOD_LENGTH - 1);
    method[MAX_METHOD_LENGTH - 1] = '\0'; // Null-terminate the string
    
    if (strcmp(method, "POST") == 0) {
        // If the method is "POST", do something
        printf("Found POST method in the packet!\n");
    } else {
        // Handle other methods
    }
}

int main() {
    char data[] = "POST /path/to/resource HTTP/1.1 ..."; // Example data
    size_t size_data = sizeof(data) - 1; // Size of data excluding null terminator
    
    processPacket(data, size_data);

    return 0;
}
