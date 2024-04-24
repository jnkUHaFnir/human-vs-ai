#include <stdio.h>
#include <string.h>

int main() {
    char str[] = {"This is the first sentence"};
    char *sentences[2]; // Array to store sentences
    char *token;
    int sentenceCount = 0;

    // Tokenize the input string based on the space character
    token = strtok(str, " ");
    while (token != NULL) {
        sentences[sentenceCount] = token;
        sentenceCount++;
        token = strtok(NULL, " ");
    }

    // Add another sentence to the array
    char str2[] = {"And this is the second"};
    token = strtok(str2, " ");
    while (token != NULL) {
        sentences[sentenceCount] = token;
        sentenceCount++;
        token = strtok(NULL, " ");
    }

    // Print the sentences in reverse order
    for (int i = sentenceCount - 1; i >= 0; i--) {
        printf("%s ", sentences[i]);
    }

    return 0;
}
