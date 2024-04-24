#include <stdio.h>
#include <string.h>

void reverseWords(char *sentence) {
    int length = strlen(sentence);

    int i;
    for (i = length - 1; i >= 0; i--) {
        if (sentence[i] == ' ') {
            sentence[i] = '\0';
            printf("%s ", &sentence[i] + 1);
        }
    }

    printf("%s ", sentence);
}

int main() {
    char sentences[2][100] = {"This is the first sentence", "And this is the second"};
    int numSentences = 2;
    int i;

    for (i = 0; i < numSentences; i++) {
        reverseWords(sentences[i]);
    }

    return 0;
}
