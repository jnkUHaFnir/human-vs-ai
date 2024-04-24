#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* align_text(char* text)
{
    int size = strlen(text);
    if(size >= 16 * 8) {
        // Text is too long to fit on the screen
        return NULL;
    }

    if(size <= 16) {
        // Single-line text
        int diff = 16 - size;
        int left_pad = diff / 2;
        int right_pad = diff - left_pad;

        char* aligned_text = (char*)malloc((16 + 1) * sizeof(char)); // Make sure to allocate space for the null terminator
        if(aligned_text == NULL) {
            return NULL; // Return NULL if memory allocation fails
        }

        memset(aligned_text, ' ', 16); // Initialize with spaces
        aligned_text[left_pad] = '\0'; // Null terminate at the aligned position
        strcat(aligned_text + left_pad, text);

        return aligned_text;
    } else {
        // Multi-line text
        char* aligned_text = (char*)malloc((16 * 8 + 1) * sizeof(char)); // Allocate space for the entire screen (16*8 characters + null terminator)
        if(aligned_text == NULL) {
            return NULL; // Return NULL if memory allocation fails
        }

        memset(aligned_text, ' ', 16 * 8); // Initialize with spaces
        aligned_text[16 * 8] = '\0'; // Null terminate

        // Tokenize the input text by space
        char* token = strtok(text, " ");
        int current_line = 0;
        while(token != NULL) {
            int token_len = strlen(token);
            if(token_len > 16) {
                // Token is too long to fit on one line
                free(aligned_text);
                return NULL;
            }

            int start_pos = (16 - token_len) / 2 + current_line * 16;
            strncpy(aligned_text + start_pos, token, token_len);

            token = strtok(NULL, " ");
            current_line += ((start_pos + token_len) / 16); // Move to the next line if needed
        }

        return aligned_text;
    }
}

int main()
{
    char input_text[] = "This is a sample text to be centered on a 16*8 screen";
    char* centered_text = align_text(input_text);

    if(centered_text != NULL) {
        printf("%s\n", centered_text);
        free(centered_text); // Free the allocated memory
    } else {
        printf("Input text is too long to fit on the screen or memory allocation failed.\n");
    }

    return 0;
}
