#include <stdio.h>
#include <string.h>

void processHttpPacket(const char* data, size_t size_data) {
    char re[size_data + 1]; // Include space for null terminator
    strncpy(re, data, size_data);
    re[size_data] = '\0'; // Null terminate the string

    char* token = strtok(re, " "); // Tokenize on space
    if (token != NULL && strcmp(token, "POST") == 0) {
        // Only execute if the first word is "POST"
        printf("Found a POST method in the HTTP packet.\n");
        // *Something happens*
    }
}

int main() {
    const char* data = "POST /example HTTP/1.1"; // Example HTTP packet
    size_t size_data = strlen(data);

    processHttpPacket(data, size_data);

    return 0;
}
