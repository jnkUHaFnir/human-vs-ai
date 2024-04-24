#include <stdio.h>
#include <string.h>

// Function to reverse each word in a string
void reverseWords(char* str) {
    int length = strlen(str);
    int i;
  
    // Traverse the string from the end
    for (i = length - 1; i >= 0; i--) {
        if (str[i] == ' ') {
            str[i] = '\0'; // Null terminate at the space
            printf("%s ", &(str[i]) + 1); // Print the word after the space
        }
    }

    // Print the first word
    printf("%s", str);
}

int main() {
    char* sentences[] = {"This is the first sentence", "And this is the second"};
    int numOfSentences = sizeof(sentences) / sizeof(sentences[0]);

    // Loop through each sentence and process
    for (int i = 0; i < numOfSentences; i++) {
        reverseWords(sentences[i]);
        if (i < numOfSentences - 1) {
            printf(" , "); // Separator for sentences, except after the last one
        }
    }

    return 0;
}
