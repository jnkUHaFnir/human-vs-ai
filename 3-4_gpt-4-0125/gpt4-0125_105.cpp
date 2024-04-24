#include <iostream>
#include <cstring>

using namespace std;

void backword(char* input, char**& output, int& wordCount) {
    int length = strlen(input);
    wordCount = 0; // To keep track of the number of words

    // First, let's allocate memory for words; assuming an average word could be 20 chars
    for(int i = 0; i < 30; i++) {
        output[i] = new char[21]; // +1 for the null terminator
        output[i][0] = '\0'; // Initialize to an empty string
    }
    
    for(int i = 0; i < length; i++) {
        if(input[i] == ' ') {
            wordCount++; // Move to next word
            if (wordCount >= 30) break; // Avoid overflow
            output[wordCount][0] = '\0'; // Initialize the next word to an empty string
        } else {
            int len = strlen(output[wordCount]); // Get the current length of the word
            output[wordCount][len] = input[i]; // Append the character
            output[wordCount][len+1] = '\0'; // Null-terminate the string
        }
    }
    
    if(input[0] != ' ') { // A non-space character at the beginning means we have at least one word
        wordCount++;
    }
}

int main() {
    char** output = new char*[30]; // Array to hold words
    int wordCount = 0;

    backword(const_cast<char*>("dfs sdfsdfsd dsffsdf"), output, wordCount); // Note: const_cast is used here to match the signature
    
    for(int i = 0; i < wordCount; i++) {
        cout << output[i] << endl; // Print each word
    }
    
    // Clean up the allocated memory
    for(int i = 0; i < 30; i++) {
        delete[] output[i];
    }
    delete[] output;
    
    return 0;
}
