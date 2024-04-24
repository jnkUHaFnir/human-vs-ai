#include <stdio.h>
#include <string.h>

// Function to reverse the words in a sentence
void reverseWords(char *str) {
    int i, j;
    for (i = strlen(str) - 1; i >= 0; i--) {
        if (str[i] == ' ') {
            printf("%s ", &(str[i]) + 1);
        }
    }
    printf("%s", str);
}

int main() {
    // Array of sentences
    char sentences[][100] = {"This is the first sentence", "And this is the second"};
    int numSentences = sizeof(sentences) / sizeof(sentences[0]);

    // Reverse the words in each sentence
    for (int i = 0; i < numSentences; i++) {
        reverseWords(sentences[i]);
        if (i < numSentences - 1) {
            printf(" "); // Add space between reversed sentences
        }
    }

    return 0;
}
