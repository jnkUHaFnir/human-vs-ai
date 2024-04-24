#include <stdio.h>
#include <string.h>

int main() {
    char str[2][50] = {"This is the first sentence", "And this is the second"};
    int num_sentences = 2;

    for (int k = 0; k < num_sentences; k++) {
        int length = strlen(str[k]);

        // Traverse string from end
        int i;
        for (i = length - 1; i >= 0; i--) {
            if (str[k][i] == ' ') {
                // putting the NULL character at the position of space characters for next iteration.
                str[k][i] = '\0';

                // Start from next character
                printf("%s ", &(str[k][i]) + 1);
            }
        }

        // printing the first word of the sentence
        printf("%s ", str[k]);
    }

    return 0;
}
