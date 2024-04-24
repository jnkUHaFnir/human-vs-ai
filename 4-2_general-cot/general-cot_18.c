#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* align_text(const char* text) {
    int i = 0, j = 0;
    char space[16], text_line[17], *final_text = NULL;

    size_t size = strlen(text);

    if (size > 128) {
        return NULL; // Text is too long for 8 lines of 16 characters
    }

    size_t num_lines = (size + 15) / 16; // Calculate number of lines needed

    final_text = (char*)malloc((128 + num_lines) * sizeof(char)); // Allocate memory for the final text
    final_text[0] = '\0';

    for (i = 0; i < num_lines; i++) {
        int diff, modulo;

        // Calculate length of the current line and padding needed for centering
        int line_length = (i == num_lines - 1) ? size % 16 : 16;
        diff = 16 - line_length;
        modulo = diff % 2;

        // Add padding spaces at the beginning of the line
        for (j = 0; j < diff / 2; j++) {
            space[j] = ' ';
        }
        space[j] = '\0';

        // Copy the current line from the text
        strncpy(text_line, text + i * 16, line_length);
        text_line[line_length] = '\0';

        // Construct the final line with padding
        if (modulo == 0) {
            sprintf(final_text, "%s%s%s%s", final_text, space, text_line, space);
        } else {
            sprintf(final_text, "%s%s%s %s", final_text, space, text_line, space);
        }

        // Add newline character for next line (except for the last line)
        if (i < num_lines - 1) {
            strcat(final_text, "\n");
        }
    }

    return final_text;
}

int main() {
    const char* input_text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor.";
    char* centered_text = align_text(input_text);

    if (centered_text) {
        printf("%s\n", centered_text);
        free(centered_text);
    } else {
        printf("Text is too long for 8 lines of 16 characters.\n");
    }

    return 0;
}
