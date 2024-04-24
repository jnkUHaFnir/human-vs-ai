#include <stdio.h>
#include <string.h>

int main() {
    char sentences[2][100] = {"This is the first sentence", "And this is the second"};
    int num_sentences = 2;

    // Process each sentence in the array
    for (int j = 0; j < num_sentences; j++) {
        char* str = sentences[j];
        int length = strlen(str);

        // Traverse string from end
        int i;
        for (i = length - 1; i >= 0; i--) {
            if (str[i] == ' ') {
                // putting the NULL character at the position of space characters for next iteration.
                str[i] = '\0';
                // Start from next character
                printf("%s ", &(str[i]) + 1);
            }
        }

        // printing the last word
        printf("%s\n", str);
    }

    return 0;
}
