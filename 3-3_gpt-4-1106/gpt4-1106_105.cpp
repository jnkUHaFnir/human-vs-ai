#include <iostream>
#include <cstring>

using namespace std;

// Split input string into words and assign to output 2D array
void splitIntoWords(char* input, char** output, int maxWords, int maxWordLength) {
    int wordIndex = 0, charIndex = 0;

    for (int i = 0; input[i] != '\0'; ++i) {
        if (input[i] == ' ') {
            output[wordIndex][charIndex] = '\0'; // Null-terminate the word
            wordIndex++;

            if (wordIndex >= maxWords)  // Prevent going past the allocated number of words
                break;

            charIndex = 0;  // Reset character index for the next word
        } else {
            if (charIndex < maxWordLength - 1) {  // Make sure there's space for the null-terminator
                output[wordIndex][charIndex++] = input[i];
            }
        }
    }

    if (wordIndex < maxWords) {
        output[wordIndex][charIndex] = '\0'; // Ensure last word is null-terminated
    }
    
    // For debug
    for (int i = 0; i <= wordIndex; ++i) {
        cout << output[i] << endl;
    }
}

int main() {
    const int MAX_WORDS = 30;    // Maximum number of words
    const int MAX_WORD_LENGTH = 20; // Maximum length of a word

    char** output = new char*[MAX_WORDS];
    for (int i = 0; i < MAX_WORDS; ++i) {
        output[i] = new char[MAX_WORD_LENGTH]; // Allocate memory for each word
    }

    splitIntoWords("dfs sdfsdfsd dsffsdf", output, MAX_WORDS, MAX_WORD_LENGTH);

    // Remember to deallocate memory
    for (int i = 0; i < MAX_WORDS; ++i) {
        delete[] output[i]; // Deallocate each string
    }

    delete[] output; // Deallocate the array of pointers

    return 0;
}
