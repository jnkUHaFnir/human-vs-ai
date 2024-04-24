#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* align_text(char* text) {
    int i = 0, j = 0;
    char space[16];
    char median[150] = "";
    char* final;

    int size = strlen(text);
    if (size >= 16 && strchr(text, ' ') == NULL) {
        // No spaces, just take the first 16 characters
        text[16] = '\0';
        return text;
    }

    int line_length = 16;
    char* start = text;
    while (*start != '\0') {
        char tmp[17];
        int word_length = strcspn(start, " ");
        if (j + word_length <= line_length) {
            strncpy(tmp, start, word_length);
            tmp[word_length] = '\0';
            strcat(median, tmp);
            j += word_length;
            if (j < line_length) {
                strcat(median, " ");
                j++;
            }
            start += word_length;
            if (*start == ' ') {
                start++;
            }
        } else {
            strcat(median, "\n");
            j = 0;
        }
    }

    final = (char*)malloc(strlen(median) + 1);
    strcpy(final, median);
    return final;
}

int main() {
    char text[] = "This is a sample text that needs to be aligned within 16*8 screen.";
    char* aligned_text = align_text(text);
    printf("%s\n", aligned_text);
    free(aligned_text);

    return 0;
}
