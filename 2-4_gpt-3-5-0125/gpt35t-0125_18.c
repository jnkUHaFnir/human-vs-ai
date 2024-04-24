#include <stdlib.h>
#include <string.h>

char* align_text(char* text) {
    char space[16];
    char median[150] = "";
    char* final;
    int line_length = 0;

    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == ' ' || line_length == 16) {
            int diff = 16 - line_length;
            int left_space = diff / 2;
            int right_space = diff - left_space;

            for (int j = 0; j < left_space; j++) {
                strcat(median, " ");
            }
            strcat(median, space);
            for (int j = 0; j < right_space; j++) {
                strcat(median, " ");
            }

            if (text[i] == ' ') {
                line_length = 0;
            }
        } else {
            median[strlen(median)] = text[i];
            line_length++;
        }
    }

    final = (char*)malloc(strlen(median) * sizeof(char));
    strcpy(final, median);
    return final;
}

int main() {
    char text[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";

    char* centered_text = align_text(text);
    printf("%s\n", centered_text);

    free(centered_text);

    return 0;
}
