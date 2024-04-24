#include <stdio.h>

void extract_tokens(char *data, int start_pos, int data_length) {
    char *token_start = data + start_pos;
    char *ptr = token_start;

    while (ptr - token_start < data_length - start_pos) {
        if (*ptr == '\0') {
            int token_length = ptr - token_start;
            char *token = malloc(token_length + 1); // +1 for null terminator
            if (token == NULL) {
                fprintf(stderr, "Memory allocation failed\n");
                return;
            }
            memcpy(token, token_start, token_length);
            token[token_length] = '\0';

            // Process the token (e.g. print it)
            printf("Token: %s\n", token);

            // Move to the start of next token
            token_start = ptr + 1;
        }
        ptr++;
    }
}

int main() {
    char data[] = "1234567890\04567890\067890";
    int start_pos = 8;
    int data_length = sizeof(data) / sizeof(data[0]);

    extract_tokens(data, start_pos, data_length);

    return 0;
}
