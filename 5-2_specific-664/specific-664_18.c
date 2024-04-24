#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* center_line(const char* line) {
    int line_len = strlen(line);
    if (line_len >= 16) {
        return strdup(line);  // Line exceeds or equals screen width, return as it is
    }

    int diff = 16 - line_len;
    int left_padding = diff / 2;
    int right_padding = diff - left_padding;

    char padded_line[17]; // Buffer for padded line
    sprintf(padded_line, "%*s%s%*s", left_padding, "", line, right_padding, "");
    
    return strdup(padded_line);
}

char* align_text(const char* text) {
    const char* delimiter = "\n";
    char* token;
    char* rest = strdup(text); // Create a copy to avoid modifying the original

    size_t final_size = 0;
    char* final = malloc(final_size + 1);
    final[0] = '\0'; // Initialize to empty string

    while ((token = strtok_r(rest, delimiter, &rest)) != NULL) {
        if (final_size > 0) {
            // Append newline character between lines
            final = realloc(final, final_size + 2);
            strcat(final, "\n");
            final_size++;
        }

        char* aligned_line = center_line(token);
        size_t aligned_line_len = strlen(aligned_line);
        final = realloc(final, final_size + aligned_line_len + 1);
        strcat(final, aligned_line);
        final_size += aligned_line_len;

        free(aligned_line); // Free memory allocated by center_line
    }

    return final;
}

int main() {
    const char* input_text = "This is a sample text to\ndemonstrate text alignment\non multiple lines.";
    char* aligned_text = align_text(input_text);

    printf("Aligned text:\n%s\n", aligned_text);

    free(aligned_text); // Free memory allocated by align_text

    return 0;
}
