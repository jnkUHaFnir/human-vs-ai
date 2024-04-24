#include <stdio.h>
#include <string.h>

void process_token(const char* token, size_t length) {
    // Process each token here
    printf("Token: %.*s\n", (int)length, token);
}

void split_by_null(const char* data, size_t data_length, size_t start_offset) {
    size_t start = start_offset;
    
    for (size_t i = start_offset; i < data_length; ++i) {
        if (data[i] == '\0') {
            size_t length = i - start;
            process_token(&data[start], length);
            start = i + 1;
        }
    }
    
    // Process last token if there's no terminating NUL character
    if (start < data_length) {
        size_t length = data_length - start;
        process_token(&data[start], length);
    }
}

int main() {
    // Example char array received over the network
    char data[] = "Hello\0World\0From\0Network\0";
    size_t data_length = sizeof(data) / sizeof(data[0]);

    // Starting index for tokens after 2 32-bit integers
    size_t start_offset = 2 * 4;

    split_by_null(data, data_length, start_offset);

    return 0;
}
