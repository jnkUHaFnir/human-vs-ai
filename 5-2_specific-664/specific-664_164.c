#include <stdio.h>
#include <string.h>

void processHTTPPacket(char* data, size_t size_data) {
    char re[size_data];
    strncpy(re, data, size_data);
    
    char* token = strtok(re, " "); // Tokenize based on space
    if (token != NULL && strcmp(token, "POST") == 0) {
        printf("First word is POST. Do something here...\n");
        // Your processing logic goes here
    } else {
        printf("First word is not POST.\n");
    }
}

int main() {
    char data[] = "POST /submit_form HTTP/1.1\r\nHost: www.example.com\r\nContent-Length: 11\r\n\r\nname=John";
    size_t size_data = sizeof(data);

    processHTTPPacket(data, size_data);

    return 0;
}
