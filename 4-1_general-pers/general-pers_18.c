#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 16
#define MAX_NUM_LINES 8

char* align_text(char* text) {
    char* lines[MAX_NUM_LINES];
    int num_lines = 0;

    char* token = strtok(text, "\n");
    while (token != NULL && num_lines < MAX_NUM_LINES) {
        lines[num_lines++] = token;
        token = strtok(NULL, "\n");
    }

    char* aligned_text = (char*)malloc(MAX_NUM_LINES * MAX_LINE_LENGTH * sizeof(char)); 
    aligned_text[0] = '\0'; // Initialize aligned_text

    for (int i = 0; i < num_lines; i++) {
        int line_length = strlen(lines[i]);
        int num_spaces = MAX_LINE_LENGTH - line_length;

        if (num_spaces % 2 != 0) {
            num_spaces++; // Add 1 extra space to make it even
        }

        int left_spaces = num_spaces / 2;
        int right_spaces = num_spaces - left_spaces;
        
        char space[left_spaces + 1];
        memset(space, ' ', left_spaces);
        space[left_spaces] = '\0';

        strcat(aligned_text, space);
        strcat(aligned_text, lines[i]);
        if (i != num_lines - 1) { // Add newline character if it's not the last line
            strcat(aligned_text, "\n");
        }

        memset(space, ' ', right_spaces);
        space[right_spaces] = '\0';
        strcat(aligned_text, space);
    }

    return aligned_text;
}

int main() {
    char text[] = "This is a long text that needs to be centered on multiple lines\nLine two\nLine three";

    char* centered_text = align_text(text);

    printf("%s\n", centered_text);

    free(centered_text); // Remember to free the allocated memory
    return 0;
}
