#include <stdio.h>
#include <string.h>

void reverseWords(char *str) {
    int length = strlen(str);
    int start = 0;
    int i;

    for (i = 0; i < length; i++) {
        if (str[i] == ' ') {
            int end = i - 1;
            while (end > start) {
                char temp = str[end];
                str[end] = str[start];
                str[start] = temp;
                end--;
                start++;
            }
            start = i + 1;
        }
    }

    // Reverse the last word
    int end = length - 1;
    while (end > start) {
        char temp = str[end];
        str[end] = str[start];
        str[start] = temp;
        end--;
        start++;
    }

    // Reverse the entire sentence
    start = 0;
    end = length - 1;
    while (start < end) {
        char temp = str[end];
        str[end] = str[start];
        str[start] = temp;
        end--;
        start++;
    }
}

int main() {
    char sentences[][100] = {"This is the first sentence", "And this is the second"};
    int numSentences = sizeof(sentences) / sizeof(sentences[0]);

    for (int j = 0; j < numSentences; j++) {
        reverseWords(sentences[j]);
        printf("%s ", sentences[j]);
    }

    return 0;
}
