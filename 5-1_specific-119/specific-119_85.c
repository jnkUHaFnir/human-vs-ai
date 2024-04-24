#include <stdio.h>
#include <string.h>

int main() {
    char sentences[][100] = {"This is the first sentence", "And this is the second"};
    int num_sentences = sizeof(sentences) / sizeof(sentences[0]);

    for (int s = 0; s < num_sentences; s++) {
        char* str = sentences[s];
        int length = strlen(str);

        // Traverse string from end
        for (int i = length - 1; i >= 0; i--) {
            if (str[i] == ' ') {
                str[i] = '\0';
                printf("%s ", &(str[i]) + 1);
            }
        }
        printf("%s\n", str);
    }

    return 0;
}
